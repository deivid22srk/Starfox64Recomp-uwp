package com.sf64recomp.app;

import android.app.Activity;
import android.content.Intent;
import android.content.pm.ActivityInfo;
import android.hardware.input.InputManager;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.view.InputDevice;
import android.view.View;
import android.view.ViewGroup;
import android.view.WindowInsets;
import android.view.WindowInsetsController;
import android.widget.RelativeLayout;

import org.libsdl.app.SDLActivity;
import org.libsdl.app.SDLControllerManager;

import java.io.File;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.util.zip.ZipEntry;
import java.util.zip.ZipInputStream;

public class MainActivity extends SDLActivity {
    private static final int REQUEST_OPEN_ROM = 1001;
    private static final int REQUEST_OPEN_DRIVER = 1002;
    private static final long HUD_POLL_INTERVAL_MS = 500L;
    private StarfoxHudView starfoxHud;
    private boolean gameRunning = false;
    private boolean gamepadConnected = false;
    private boolean pollerStarted = false;
    private final Handler hudPoller = new Handler(Looper.getMainLooper());
    private final Runnable hudPollTask = new Runnable() {
        @Override
        public void run() {
            if (!pollerStarted) {
                return;
            }
            gameRunning = nativeIsGameRunning();
            gamepadConnected = isPhysicalGamepadConnected();
            refreshHudVisibility();
            hudPoller.postDelayed(this, HUD_POLL_INTERVAL_MS);
        }
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        extractAssets();
        super.onCreate(savedInstanceState);
        setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_SENSOR_LANDSCAPE);
        installStarfoxHud();
        startHudPoller();
        enableImmersiveMode();
    }

    private void installStarfoxHud() {
        if (mLayout == null || mSurface == null) {
            return;
        }
        starfoxHud = new StarfoxHudView(this);
        RelativeLayout.LayoutParams params = new RelativeLayout.LayoutParams(
            ViewGroup.LayoutParams.MATCH_PARENT,
            ViewGroup.LayoutParams.MATCH_PARENT
        );
        params.addRule(RelativeLayout.ALIGN_PARENT_TOP);
        params.addRule(RelativeLayout.ALIGN_PARENT_BOTTOM);
        params.addRule(RelativeLayout.ALIGN_PARENT_START);
        params.addRule(RelativeLayout.ALIGN_PARENT_END);
        mLayout.addView(starfoxHud, params);
        starfoxHud.bringToFront();
    }

    private final InputManager.InputDeviceListener inputDeviceListener = new InputManager.InputDeviceListener() {
        @Override
        public void onInputDeviceAdded(int deviceId) {
            gamepadConnected = isPhysicalGamepadConnected();
            refreshHudVisibility();
        }

        @Override
        public void onInputDeviceRemoved(int deviceId) {
            gamepadConnected = isPhysicalGamepadConnected();
            refreshHudVisibility();
        }

        @Override
        public void onInputDeviceChanged(int deviceId) {
            gamepadConnected = isPhysicalGamepadConnected();
            refreshHudVisibility();
        }
    };

    private boolean isPhysicalGamepadConnected() {
        for (int deviceId : InputDevice.getDeviceIds()) {
            try {
                if (SDLControllerManager.isDeviceSDLJoystick(deviceId)) {
                    return true;
                }
            } catch (Exception ignored) {
            }
        }
        return false;
    }

    private void startHudPoller() {
        if (pollerStarted) {
            return;
        }
        pollerStarted = true;
        InputManager inputManager = (InputManager) getSystemService(INPUT_SERVICE);
        if (inputManager != null) {
            inputManager.registerInputDeviceListener(inputDeviceListener, hudPoller);
        }
        hudPoller.post(hudPollTask);
    }

    private void stopHudPoller() {
        pollerStarted = false;
        hudPoller.removeCallbacks(hudPollTask);
        InputManager inputManager = (InputManager) getSystemService(INPUT_SERVICE);
        if (inputManager != null) {
            inputManager.unregisterInputDeviceListener(inputDeviceListener);
        }
    }

    private void refreshHudVisibility() {
        if (starfoxHud == null) {
            return;
        }
        boolean show = gameRunning && !gamepadConnected;
        if (starfoxHud.isHudVisible() != show) {
            starfoxHud.setHudVisible(show);
        }
    }

    @Override
    protected void onPause() {
        super.onPause();
        stopHudPoller();
    }

    @Override
    protected void onResume() {
        super.onResume();
        startHudPoller();
    }

    @Override
    public void onWindowFocusChanged(boolean hasFocus) {
        super.onWindowFocusChanged(hasFocus);
        if (hasFocus) {
            enableImmersiveMode();
        }
    }

    private void enableImmersiveMode() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.R) {
            getWindow().setDecorFitsSystemWindows(false);
            WindowInsetsController controller = getWindow().getInsetsController();
            if (controller != null) {
                controller.hide(WindowInsets.Type.statusBars() | WindowInsets.Type.navigationBars());
                controller.setSystemBarsBehavior(WindowInsetsController.BEHAVIOR_SHOW_TRANSIENT_BARS_BY_SWIPE);
            }
        } else {
            getWindow().getDecorView().setSystemUiVisibility(
                View.SYSTEM_UI_FLAG_IMMERSIVE_STICKY
                | View.SYSTEM_UI_FLAG_FULLSCREEN
                | View.SYSTEM_UI_FLAG_HIDE_NAVIGATION
                | View.SYSTEM_UI_FLAG_LAYOUT_STABLE
                | View.SYSTEM_UI_FLAG_LAYOUT_FULLSCREEN
                | View.SYSTEM_UI_FLAG_LAYOUT_HIDE_NAVIGATION
            );
        }
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

    public static void openDriverPicker() {
        Intent intent = new Intent(Intent.ACTION_OPEN_DOCUMENT);
        intent.addCategory(Intent.CATEGORY_OPENABLE);
        intent.setType("application/zip");
        Activity activity = (Activity) SDLActivity.mSingleton;
        activity.startActivityForResult(intent, REQUEST_OPEN_DRIVER);
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
        } else if (requestCode == REQUEST_OPEN_DRIVER) {
            String path = "";
            if (resultCode == RESULT_OK && data != null && data.getData() != null) {
                String extracted = extractDriverFromZip(data.getData());
                if (extracted != null) {
                    path = extracted;
                }
            }
            nativeOnDriverSelected(path);
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

    private String extractDriverFromZip(Uri uri) {
        try {
            InputStream in = getContentResolver().openInputStream(uri);
            if (in == null) {
                return null;
            }

            File driverDir = new File(getFilesDir(), "driver");
            driverDir.mkdirs();

            ZipInputStream zis = new ZipInputStream(in);
            ZipEntry entry;
            String soPath = null;
            byte[] buf = new byte[65536];

            while ((entry = zis.getNextEntry()) != null) {
                String entryName = entry.getName();
                if (entryName.endsWith(".so") && !entry.isDirectory()) {
                    String fileName = entryName.substring(entryName.lastIndexOf('/') + 1);
                    File outFile = new File(driverDir, fileName);
                    FileOutputStream fos = new FileOutputStream(outFile);
                    int n;
                    while ((n = zis.read(buf)) != -1) {
                        fos.write(buf, 0, n);
                    }
                    fos.close();
                    soPath = outFile.getAbsolutePath();
                }
                zis.closeEntry();
            }
            zis.close();
            in.close();
            return soPath;
        } catch (Exception e) {
            return null;
        }
    }

    private static native void nativeOnRomSelected(String path);
    private static native void nativeOnDriverSelected(String path);
    private static native boolean nativeIsGameRunning();
}
