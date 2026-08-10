package com.sf64recomp.app;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.RectF;
import android.view.KeyEvent;
import android.view.MotionEvent;
import android.view.View;

import org.libsdl.app.SDLActivity;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/**
 * Star Fox 64-specific flight HUD. This is intentionally not a generic
 * controller: the left pad is a flight stick and the right cluster exposes
 * the game's combat and maneuver actions.
 */
public final class StarfoxHudView extends View {
    private static final int ACTION_NONE = 0;
    private static final int ACTION_STICK = 1;
    private static final int ACTION_LASER = 2;
    private static final int ACTION_BOMB = 3;
    private static final int ACTION_TURBO = 4;
    private static final int ACTION_BRAKE = 5;
    private static final int ACTION_ROLL_LEFT = 6;
    private static final int ACTION_ROLL_RIGHT = 7;
    private static final int ACTION_CAMERA = 8;
    private static final int ACTION_ROB = 9;
    private static final int ACTION_PAUSE = 10;

    private static final int KEY_UP = KeyEvent.KEYCODE_W;
    private static final int KEY_DOWN = KeyEvent.KEYCODE_S;
    private static final int KEY_LEFT = KeyEvent.KEYCODE_A;
    private static final int KEY_RIGHT = KeyEvent.KEYCODE_D;

    // D-pad keycodes are runtime constants on Android; declare the numeric
    // values here so the HUD compiles against the plain JDK used by Gradle.
    private static final int KEYCODE_DPAD_LEFT = 21;
    private static final int KEYCODE_DPAD_RIGHT = 22;
    private static final int KEYCODE_DPAD_UP = 19;
    private static final int KEYCODE_DPAD_DOWN = 20;

    private static final int COLOR_CYAN = Color.rgb(154, 226, 224);
    private static final int COLOR_TEXT = Color.rgb(221, 240, 235);
    private static final int COLOR_ORANGE = Color.rgb(247, 178, 91);
    private static final int COLOR_PANEL = Color.argb(112, 4, 15, 21);
    private static final int COLOR_ACTIVE = Color.argb(220, 154, 226, 224);

    private final Paint paint = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Paint linePaint = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Map<Integer, Integer> pointerActions = new HashMap<>();
    private final Set<Integer> heldKeys = new HashSet<>();
    private final Set<Integer> pressedActions = new HashSet<>();
    private float density;
    private float stickX;
    private float stickY;
    private boolean visible = true;

    public StarfoxHudView(Context context) {
        super(context);
        density = getResources().getDisplayMetrics().density;
        setFocusable(false);
        setClickable(true);
        paint.setTypeface(android.graphics.Typeface.create("sans-serif", android.graphics.Typeface.BOLD));
        linePaint.setStyle(Paint.Style.STROKE);
        linePaint.setStrokeWidth(dp(2));
        linePaint.setStrokeCap(Paint.Cap.ROUND);
        setLayerType(View.LAYER_TYPE_SOFTWARE, null);
    }

    private float dp(float value) {
        return value * density;
    }

    @Override
    protected void onDraw(Canvas canvas) {
        super.onDraw(canvas);
        if (!visible) {
            return;
        }

        float w = getWidth();
        float h = getHeight();
        float unit = Math.min(w, h);
        float stickRadius = Math.max(dp(58), unit * 0.13f);
        float stickCx = dp(26) + stickRadius;
        float stickCy = h - dp(28) - stickRadius;
        float buttonRadius = Math.max(dp(27), unit * 0.052f);
        stickX = stickCx;
        stickY = stickCy;

        drawFlightStick(canvas, stickCx, stickCy, stickRadius);
        drawCombatCluster(canvas, w, h, buttonRadius);
        drawPause(canvas, w, h);
    }

    private void drawFlightStick(Canvas canvas, float cx, float cy, float radius) {
        linePaint.setColor(Color.argb(170, 154, 226, 224));
        linePaint.setStrokeWidth(dp(1.5f));
        canvas.drawCircle(cx, cy, radius, linePaint);
        canvas.drawCircle(cx, cy, radius * 0.48f, linePaint);
        canvas.drawLine(cx - radius, cy, cx + radius, cy, linePaint);
        canvas.drawLine(cx, cy - radius, cx, cy + radius, linePaint);

        float knobX = cx;
        float knobY = cy;
        if (heldKeys.contains(KEY_LEFT)) knobX -= radius * 0.42f;
        if (heldKeys.contains(KEY_RIGHT)) knobX += radius * 0.42f;
        if (heldKeys.contains(KEY_UP)) knobY -= radius * 0.42f;
        if (heldKeys.contains(KEY_DOWN)) knobY += radius * 0.42f;
        paint.setColor(COLOR_CYAN);
        canvas.drawCircle(knobX, knobY, radius * 0.13f, paint);
        paint.setColor(COLOR_TEXT);
        paint.setTextSize(dp(9));
        paint.setTextAlign(Paint.Align.CENTER);
        canvas.drawText("FLIGHT", cx, cy + radius + dp(16), paint);
        paint.setTextAlign(Paint.Align.LEFT);
    }

    private void drawCombatCluster(Canvas canvas, float w, float h, float r) {
        float right = w - dp(24);
        float y = h - dp(38) - r * 2.3f;
        float gap = dp(8);
        float laserX = right - r * 2 - gap;
        float bombX = right - r;
        drawActionCircle(canvas, laserX, y, r, ACTION_LASER, "A", "LASER");
        drawActionCircle(canvas, bombX, y, r, ACTION_BOMB, "B", "BOMB");

        float utilityY = h - dp(38);
        float utilityWidth = dp(72);
        float utilityLeft = w - dp(24) - utilityWidth * 2 - gap;
        drawActionPill(canvas, utilityLeft, utilityY, utilityWidth, dp(28), ACTION_TURBO, "TURBO");
        drawActionPill(canvas, utilityLeft + utilityWidth + gap, utilityY, utilityWidth, dp(28), ACTION_BRAKE, "BRAKE");

        float top = dp(18);
        float width = dp(68);
        float start = w - dp(24) - width * 4 - gap * 3;
        drawActionPill(canvas, start, top, width, dp(27), ACTION_ROLL_LEFT, "ROLL L");
        drawActionPill(canvas, start + width + gap, top, width, dp(27), ACTION_ROLL_RIGHT, "ROLL R");
        drawActionPill(canvas, start + (width + gap) * 2, top, width, dp(27), ACTION_CAMERA, "CAMERA");
        drawActionPill(canvas, start + (width + gap) * 3, top, width, dp(27), ACTION_ROB, "ROB");
    }

    private void drawActionCircle(Canvas canvas, float cx, float cy, float radius, int action, String glyph, String label) {
        boolean pressed = pressedActions.contains(action);
        paint.setColor(pressed ? COLOR_ACTIVE : COLOR_PANEL);
        canvas.drawCircle(cx, cy, radius, paint);
        linePaint.setColor(pressed ? COLOR_TEXT : COLOR_ORANGE);
        linePaint.setStrokeWidth(dp(2));
        canvas.drawCircle(cx, cy, radius, linePaint);
        paint.setColor(pressed ? Color.rgb(20, 42, 43) : COLOR_TEXT);
        paint.setTextAlign(Paint.Align.CENTER);
        paint.setTextSize(dp(19));
        canvas.drawText(glyph, cx, cy + dp(6), paint);
        paint.setTextSize(dp(8));
        canvas.drawText(label, cx, cy + radius + dp(13), paint);
        paint.setTextAlign(Paint.Align.LEFT);
    }

    private void drawActionPill(Canvas canvas, float left, float top, float width, float height, int action, String label) {
        boolean pressed = pressedActions.contains(action);
        paint.setColor(pressed ? COLOR_ACTIVE : COLOR_PANEL);
        canvas.drawRoundRect(new RectF(left, top, left + width, top + height), height / 2, height / 2, paint);
        linePaint.setColor(pressed ? COLOR_TEXT : Color.argb(180, 154, 226, 224));
        linePaint.setStrokeWidth(dp(1));
        canvas.drawRoundRect(new RectF(left, top, left + width, top + height), height / 2, height / 2, linePaint);
        paint.setColor(pressed ? Color.rgb(20, 42, 43) : COLOR_TEXT);
        paint.setTextAlign(Paint.Align.CENTER);
        paint.setTextSize(dp(8));
        canvas.drawText(label, left + width / 2, top + height / 2 + dp(3), paint);
        paint.setTextAlign(Paint.Align.LEFT);
    }

    private void drawPause(Canvas canvas, float w, float h) {
        float left = w - dp(76);
        float top = dp(52);
        drawActionPill(canvas, left, top, dp(52), dp(27), ACTION_PAUSE, "PAUSE");
    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {
        if (!visible) {
            return false;
        }
        int action = event.getActionMasked();
        if (action == MotionEvent.ACTION_DOWN || action == MotionEvent.ACTION_POINTER_DOWN) {
            int index = event.getActionIndex();
            int pointerId = event.getPointerId(index);
            int hudAction = hitTest(event.getX(index), event.getY(index));
            pointerActions.put(pointerId, hudAction);
            pressAction(hudAction, event.getX(index), event.getY(index));
            invalidate();
            return hudAction != ACTION_NONE;
        }
        if (action == MotionEvent.ACTION_MOVE) {
            for (int i = 0; i < event.getPointerCount(); i++) {
                int pointerId = event.getPointerId(i);
                int oldAction = pointerActions.containsKey(pointerId) ? pointerActions.get(pointerId) : ACTION_NONE;
                if (oldAction == ACTION_STICK) {
                    updateStick(event.getX(i), event.getY(i));
                }
            }
            invalidate();
            return true;
        }
        if (action == MotionEvent.ACTION_UP || action == MotionEvent.ACTION_POINTER_UP) {
            int index = event.getActionIndex();
            int pointerId = event.getPointerId(index);
            int hudAction = pointerActions.containsKey(pointerId) ? pointerActions.remove(pointerId) : ACTION_NONE;
            releaseAction(hudAction);
            invalidate();
            return true;
        }
        if (action == MotionEvent.ACTION_CANCEL) {
            pointerActions.clear();
            releaseAll();
            invalidate();
            return true;
        }
        return true;
    }

    private int hitTest(float x, float y) {
        float w = getWidth();
        float h = getHeight();
        float unit = Math.min(w, h);
        float stickRadius = Math.max(dp(58), unit * 0.13f) + dp(18);
        if (Math.hypot(x - stickX, y - stickY) <= stickRadius) {
            return ACTION_STICK;
        }
        float buttonRadius = Math.max(dp(27), unit * 0.052f) + dp(8);
        float right = w - dp(24);
        float combatY = h - dp(38) - buttonRadius * 2.3f;
        float gap = dp(8);
        if (Math.hypot(x - (right - buttonRadius * 2 - gap), y - combatY) <= buttonRadius) return ACTION_LASER;
        if (Math.hypot(x - (right - buttonRadius), y - combatY) <= buttonRadius) return ACTION_BOMB;

        float utilityWidth = dp(72);
        float utilityLeft = w - dp(24) - utilityWidth * 2 - gap;
        if (inPill(x, y, utilityLeft, h - dp(38), utilityWidth, dp(28))) return ACTION_TURBO;
        if (inPill(x, y, utilityLeft + utilityWidth + gap, h - dp(38), utilityWidth, dp(28))) return ACTION_BRAKE;

        float top = dp(18);
        float width = dp(68);
        float start = w - dp(24) - width * 4 - gap * 3;
        if (inPill(x, y, start, top, width, dp(27))) return ACTION_ROLL_LEFT;
        if (inPill(x, y, start + width + gap, top, width, dp(27))) return ACTION_ROLL_RIGHT;
        if (inPill(x, y, start + (width + gap) * 2, top, width, dp(27))) return ACTION_CAMERA;
        if (inPill(x, y, start + (width + gap) * 3, top, width, dp(27))) return ACTION_ROB;
        if (inPill(x, y, w - dp(76), dp(52), dp(52), dp(27))) return ACTION_PAUSE;
        return ACTION_NONE;
    }

    private boolean inPill(float x, float y, float left, float top, float width, float height) {
        return x >= left - dp(5) && x <= left + width + dp(5) && y >= top - dp(5) && y <= top + height + dp(5);
    }

    private void pressAction(int action, float x, float y) {
        if (action == ACTION_STICK) {
            updateStick(x, y);
            return;
        }
        if (action == ACTION_NONE) return;
        pressedActions.add(action);
        switch (action) {
            case ACTION_LASER: sendKey(KeyEvent.KEYCODE_SPACE, true); break;
            case ACTION_BOMB: sendKey(KeyEvent.KEYCODE_SHIFT_LEFT, true); break;
            case ACTION_TURBO: sendKey(KEYCODE_DPAD_LEFT, true); break;
            case ACTION_BRAKE: sendKey(KEYCODE_DPAD_DOWN, true); break;
            case ACTION_ROLL_LEFT: sendKey(KeyEvent.KEYCODE_Q, true); break;
            case ACTION_ROLL_RIGHT: sendKey(KeyEvent.KEYCODE_R, true); break;
            case ACTION_CAMERA: sendKey(KEYCODE_DPAD_UP, true); break;
            case ACTION_ROB: sendKey(KEYCODE_DPAD_RIGHT, true); break;
            case ACTION_PAUSE: sendKey(KeyEvent.KEYCODE_ENTER, true); break;
            default: break;
        }
    }

    private void releaseAction(int action) {
        if (action == ACTION_STICK) {
            clearStick();
            return;
        }
        if (action == ACTION_NONE) return;
        pressedActions.remove(action);
        switch (action) {
            case ACTION_LASER: sendKey(KeyEvent.KEYCODE_SPACE, false); break;
            case ACTION_BOMB: sendKey(KeyEvent.KEYCODE_SHIFT_LEFT, false); break;
            case ACTION_TURBO: sendKey(KEYCODE_DPAD_LEFT, false); break;
            case ACTION_BRAKE: sendKey(KEYCODE_DPAD_DOWN, false); break;
            case ACTION_ROLL_LEFT: sendKey(KeyEvent.KEYCODE_Q, false); break;
            case ACTION_ROLL_RIGHT: sendKey(KeyEvent.KEYCODE_R, false); break;
            case ACTION_CAMERA: sendKey(KEYCODE_DPAD_UP, false); break;
            case ACTION_ROB: sendKey(KEYCODE_DPAD_RIGHT, false); break;
            case ACTION_PAUSE: sendKey(KeyEvent.KEYCODE_ENTER, false); break;
            default: break;
        }
    }

    private void updateStick(float x, float y) {
        float dx = x - stickX;
        float dy = y - stickY;
        float threshold = Math.max(dp(22), Math.min(getWidth(), getHeight()) * 0.045f);
        setHeldKey(KEY_LEFT, dx < -threshold);
        setHeldKey(KEY_RIGHT, dx > threshold);
        setHeldKey(KEY_UP, dy < -threshold);
        setHeldKey(KEY_DOWN, dy > threshold);
    }

    private void clearStick() {
        setHeldKey(KEY_LEFT, false);
        setHeldKey(KEY_RIGHT, false);
        setHeldKey(KEY_UP, false);
        setHeldKey(KEY_DOWN, false);
    }

    private void setHeldKey(int keyCode, boolean held) {
        if (held && heldKeys.add(keyCode)) {
            sendKey(keyCode, true);
        } else if (!held && heldKeys.remove(keyCode)) {
            sendKey(keyCode, false);
        }
    }

    private void sendKey(int keyCode, boolean down) {
        if (down) {
            SDLActivity.onNativeKeyDown(keyCode);
        } else {
            SDLActivity.onNativeKeyUp(keyCode);
        }
    }

    private void releaseAll() {
        clearStick();
        for (Integer action : new HashSet<>(pressedActions)) {
            releaseAction(action);
        }
        pressedActions.clear();
    }

    public void setHudVisible(boolean visible) {
        this.visible = visible;
        if (!visible) releaseAll();
        setVisibility(visible ? View.VISIBLE : View.INVISIBLE);
        invalidate();
    }

    public boolean isHudVisible() {
        return visible;
    }
}
