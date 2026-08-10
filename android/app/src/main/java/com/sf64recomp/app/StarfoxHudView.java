package com.sf64recomp.app;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Path;
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
        float stickRadius = Math.max(dp(64), unit * 0.145f);
        float stickCx = unit * 0.19f;
        float stickCy = h - unit * 0.22f;
        float buttonRadius = Math.max(dp(30), unit * 0.055f);
        stickX = stickCx;
        stickY = stickCy;

        drawTopReadout(canvas, w, h);
        drawFlightStick(canvas, stickCx, stickCy, stickRadius);
        drawCombatCluster(canvas, w, h, buttonRadius);
        drawPause(canvas, w, h);
    }

    private void drawTopReadout(Canvas canvas, float w, float h) {
        float left = dp(18);
        float top = dp(16);
        paint.setColor(Color.argb(150, 9, 25, 35));
        canvas.drawRoundRect(new RectF(left, top, left + dp(208), top + dp(38)), dp(7), dp(7), paint);
        paint.setColor(Color.rgb(111, 218, 230));
        paint.setTextSize(dp(12));
        canvas.drawText("ARWING // FLIGHT DECK", left + dp(12), top + dp(16), paint);
        paint.setColor(Color.argb(210, 214, 238, 231));
        paint.setTextSize(dp(10));
        canvas.drawText("TOUCH HUD", left + dp(12), top + dp(30), paint);
    }

    private void drawFlightStick(Canvas canvas, float cx, float cy, float radius) {
        paint.setColor(Color.argb(100, 9, 26, 36));
        canvas.drawCircle(cx, cy, radius + dp(13), paint);
        linePaint.setColor(Color.argb(190, 96, 205, 216));
        linePaint.setStrokeWidth(dp(2));
        canvas.drawCircle(cx, cy, radius, linePaint);
        canvas.drawCircle(cx, cy, radius * 0.56f, linePaint);
        canvas.drawLine(cx - radius, cy, cx + radius, cy, linePaint);
        canvas.drawLine(cx, cy - radius, cx, cy + radius, linePaint);

        float knobX = cx;
        float knobY = cy;
        if (heldKeys.contains(KEY_LEFT)) knobX -= radius * 0.46f;
        if (heldKeys.contains(KEY_RIGHT)) knobX += radius * 0.46f;
        if (heldKeys.contains(KEY_UP)) knobY -= radius * 0.46f;
        if (heldKeys.contains(KEY_DOWN)) knobY += radius * 0.46f;
        paint.setColor(Color.argb(225, 111, 218, 230));
        canvas.drawCircle(knobX, knobY, radius * 0.18f, paint);
        paint.setColor(Color.argb(225, 214, 238, 231));
        paint.setTextSize(dp(10));
        paint.setTextAlign(Paint.Align.CENTER);
        canvas.drawText("FLIGHT", cx, cy + radius + dp(23), paint);
        paint.setTextAlign(Paint.Align.LEFT);
    }

    private void drawCombatCluster(Canvas canvas, float w, float h, float r) {
        float right = w - dp(22);
        float y = h - Math.max(dp(140), h * 0.23f);
        float laserX = right - r * 1.25f;
        float bombX = right;
        drawActionCircle(canvas, laserX, y, r, ACTION_LASER, "A", "LASER");
        drawActionCircle(canvas, bombX, y + r * 1.35f, r, ACTION_BOMB, "B", "BOMB");

        float utilityY = h - dp(43);
        drawActionPill(canvas, w * 0.60f, utilityY, dp(76), dp(34), ACTION_TURBO, "TURBO");
        drawActionPill(canvas, w * 0.60f + dp(84), utilityY, dp(76), dp(34), ACTION_BRAKE, "BRAKE");

        drawActionPill(canvas, w * 0.61f, dp(66), dp(82), dp(32), ACTION_ROLL_LEFT, "ROLL L");
        drawActionPill(canvas, w * 0.61f + dp(90), dp(66), dp(82), dp(32), ACTION_ROLL_RIGHT, "ROLL R");
        drawActionPill(canvas, w * 0.61f + dp(180), dp(66), dp(82), dp(32), ACTION_CAMERA, "CAMERA");
        drawActionPill(canvas, w * 0.61f + dp(270), dp(66), dp(72), dp(32), ACTION_ROB, "ROB");
    }

    private void drawActionCircle(Canvas canvas, float cx, float cy, float radius, int action, String glyph, String label) {
        boolean pressed = pressedActions.contains(action);
        paint.setColor(pressed ? Color.argb(225, 243, 164, 72) : Color.argb(185, 16, 42, 52));
        canvas.drawCircle(cx, cy, radius, paint);
        linePaint.setColor(pressed ? Color.rgb(255, 224, 151) : Color.rgb(243, 164, 72));
        linePaint.setStrokeWidth(dp(3));
        canvas.drawCircle(cx, cy, radius, linePaint);
        paint.setColor(pressed ? Color.rgb(30, 45, 48) : Color.rgb(245, 214, 155));
        paint.setTextAlign(Paint.Align.CENTER);
        paint.setTextSize(dp(22));
        canvas.drawText(glyph, cx, cy + dp(7), paint);
        paint.setTextSize(dp(9));
        canvas.drawText(label, cx, cy + radius + dp(16), paint);
        paint.setTextAlign(Paint.Align.LEFT);
    }

    private void drawActionPill(Canvas canvas, float left, float top, float width, float height, int action, String label) {
        boolean pressed = pressedActions.contains(action);
        paint.setColor(pressed ? Color.argb(225, 83, 171, 180) : Color.argb(150, 10, 31, 41));
        canvas.drawRoundRect(new RectF(left, top, left + width, top + height), height / 2, height / 2, paint);
        linePaint.setColor(pressed ? Color.rgb(214, 238, 231) : Color.argb(190, 111, 218, 230));
        linePaint.setStrokeWidth(dp(1.5f));
        canvas.drawRoundRect(new RectF(left, top, left + width, top + height), height / 2, height / 2, linePaint);
        paint.setColor(Color.rgb(214, 238, 231));
        paint.setTextAlign(Paint.Align.CENTER);
        paint.setTextSize(dp(9));
        canvas.drawText(label, left + width / 2, top + height / 2 + dp(3), paint);
        paint.setTextAlign(Paint.Align.LEFT);
    }

    private void drawPause(Canvas canvas, float w, float h) {
        float left = w - dp(76);
        float top = dp(15);
        drawActionPill(canvas, left, top, dp(58), dp(32), ACTION_PAUSE, "PAUSE");
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
        float stickRadius = Math.max(dp(64), unit * 0.145f) + dp(18);
        if (Math.hypot(x - stickX, y - stickY) <= stickRadius) {
            return ACTION_STICK;
        }
        float buttonRadius = Math.max(dp(30), unit * 0.055f) + dp(8);
        float right = w - dp(22);
        float combatY = h - Math.max(dp(140), h * 0.23f);
        if (Math.hypot(x - (right - buttonRadius * 1.25f), y - combatY) <= buttonRadius) return ACTION_LASER;
        if (Math.hypot(x - right, y - (combatY + buttonRadius * 1.35f)) <= buttonRadius) return ACTION_BOMB;
        if (inPill(x, y, w * 0.60f, h - dp(43), dp(76), dp(34))) return ACTION_TURBO;
        if (inPill(x, y, w * 0.60f + dp(84), h - dp(43), dp(76), dp(34))) return ACTION_BRAKE;
        if (inPill(x, y, w * 0.61f, dp(66), dp(82), dp(32))) return ACTION_ROLL_LEFT;
        if (inPill(x, y, w * 0.61f + dp(90), dp(66), dp(82), dp(32))) return ACTION_ROLL_RIGHT;
        if (inPill(x, y, w * 0.61f + dp(180), dp(66), dp(82), dp(32))) return ACTION_CAMERA;
        if (inPill(x, y, w * 0.61f + dp(270), dp(66), dp(72), dp(32))) return ACTION_ROB;
        if (inPill(x, y, w - dp(76), dp(15), dp(58), dp(32))) return ACTION_PAUSE;
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
            case ACTION_TURBO: sendKey(KeyEvent.KEYCODE_LEFT, true); break;
            case ACTION_BRAKE: sendKey(KeyEvent.KEYCODE_DOWN, true); break;
            case ACTION_ROLL_LEFT: sendKey(KeyEvent.KEYCODE_Q, true); break;
            case ACTION_ROLL_RIGHT: sendKey(KeyEvent.KEYCODE_R, true); break;
            case ACTION_CAMERA: sendKey(KeyEvent.KEYCODE_UP, true); break;
            case ACTION_ROB: sendKey(KeyEvent.KEYCODE_RIGHT, true); break;
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
            case ACTION_TURBO: sendKey(KeyEvent.KEYCODE_LEFT, false); break;
            case ACTION_BRAKE: sendKey(KeyEvent.KEYCODE_DOWN, false); break;
            case ACTION_ROLL_LEFT: sendKey(KeyEvent.KEYCODE_Q, false); break;
            case ACTION_ROLL_RIGHT: sendKey(KeyEvent.KEYCODE_R, false); break;
            case ACTION_CAMERA: sendKey(KeyEvent.KEYCODE_UP, false); break;
            case ACTION_ROB: sendKey(KeyEvent.KEYCODE_RIGHT, false); break;
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
        invalidate();
    }

    public boolean isHudVisible() {
        return visible;
    }
}
