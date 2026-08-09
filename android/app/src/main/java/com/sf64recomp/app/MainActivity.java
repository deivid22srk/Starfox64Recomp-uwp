package com.sf64recomp.app;

import android.app.Activity;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;

import org.libsdl.app.SDLActivity;

import java.io.File;
import java.io.FileOutputStream;
import java.io.InputStream;

public class MainActivity extends SDLActivity {
    private static final int REQUEST_OPEN_ROM = 1001;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        extractAssets();
        super.onCreate(savedInstanceState);
    }

    // Copies the packaged assets (rcss, rml, fonts, icons) out of the APK into
    // the app's internal storage so the native code can read them as regular files.
    private void extractAssets() {
        try {
            File destDir = new File(getFilesDir(), "assets");
            destDir.mkdirs();
            copyAssetDir("", destDir);
        } catch (Exception ignored) {
        }
    }

    private void copyAssetDir(String assetPath, File destDir) {
        try {
            String[] children = getAssets().list(assetPath);
            if (children == null) {
                return;
            }
            for (String child : children) {
                String childPath = assetPath.isEmpty() ? child : assetPath + "/" + child;
                String[] sub = getAssets().list(childPath);
                if (sub != null && sub.length > 0) {
                    File subDir = new File(destDir, child);
                    subDir.mkdirs();
                    copyAssetDir(childPath, subDir);
                } else {
                    File outFile = new File(destDir, child);
                    if (outFile.exists()) {
                        continue;
                    }
                    InputStream in = getAssets().open(childPath);
                    FileOutputStream out = new FileOutputStream(outFile);
                    byte[] buf = new byte[65536];
                    int n;
                    while ((n = in.read(buf)) != -1) {
                        out.write(buf, 0, n);
                    }
                    out.close();
                    in.close();
                }
            }
        } catch (Exception ignored) {
        }
    }

    // Called from native code to launch the system file picker.
    public static void openRomPicker() {
        Intent intent = new Intent(Intent.ACTION_OPEN_DOCUMENT);
        intent.addCategory(Intent.CATEGORY_OPENABLE);
        intent.setType("*/*");
        Activity activity = (Activity) SDLActivity.mSingleton;
        activity.startActivityForResult(intent, REQUEST_OPEN_ROM);
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if (requestCode == REQUEST_OPEN_ROM) {
            String path = "";
            if (resultCode == RESULT_OK && data != null && data.getData() != null) {
                String copied = copyToInternalStorage(data.getData());
                if (copied != null) {
                    path = copied;
                }
            }
            nativeOnRomSelected(path);
        }
    }

    private String copyToInternalStorage(Uri uri) {
        try {
            InputStream in = getContentResolver().openInputStream(uri);
            if (in == null) {
                return null;
            }

            String name = uri.getLastPathSegment();
            String ext = ".z64";
            if (name != null) {
                int dot = name.lastIndexOf('.');
                if (dot >= 0) {
                    String candidate = name.substring(dot).toLowerCase();
                    if (candidate.equals(".z64") || candidate.equals(".n64") || candidate.equals(".v64")) {
                        ext = candidate;
                    }
                }
            }

            File dir = new File(getFilesDir(), "roms");
            dir.mkdirs();
            File out = new File(dir, "rom" + ext);

            FileOutputStream fos = new FileOutputStream(out);
            byte[] buf = new byte[65536];
            int n;
            while ((n = in.read(buf)) != -1) {
                fos.write(buf, 0, n);
            }
            fos.close();
            in.close();
            return out.getAbsolutePath();
        } catch (Exception e) {
            return null;
        }
    }

    private static native void nativeOnRomSelected(String path);
}
