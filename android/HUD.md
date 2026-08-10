# Star Fox 64 Android HUD

A dedicated touch HUD is enabled automatically on Android. It is designed around the Arwing flight loop rather than presenting a generic virtual controller.

## Layout

- **Flight stick**: the lower-left ring drives pitch and yaw. Dragging away from the center emits the existing `W/A/S/D` keyboard bindings, so controller mappings and native input handling remain unchanged.
- **A / Laser**: lower-right primary fire button.
- **B / Bomb**: lower-right secondary button for Smart Bomb.
- **TURBO / BRAKE**: flight utility pills along the bottom edge.
- **ROLL L / ROLL R**: tilt/barrel-roll actions at the top of the HUD.
- **CAMERA / ROB**: context actions near the top-right.
- **PAUSE**: compact control in the upper-right corner.

Buttons use a restrained cockpit palette, press feedback, and labels for one-handed play. The HUD scales from the shorter display dimension and is restricted to landscape orientation.

## Input mapping

The HUD emits the same Android key events already accepted by SDL and the project's default mappings:

| HUD action | Existing game binding |
| --- | --- |
| Flight stick | `W/A/S/D` analog directions |
| Laser | `Space` / N64 A |
| Smart Bomb | `Left Shift` / N64 B |
| Turbo | `Left Arrow` / C-left |
| Brake | `Down Arrow` / C-down |
| Roll left/right | `Q` / `R` / N64 Z/R |
| Camera | `Up Arrow` / C-up |
| ROB Message | `Right Arrow` / C-right |
| Pause | `Enter` / Start |

The view is placed above the SDL surface by `MainActivity` and consumes only touches in its own controls, leaving the game renderer and physical controllers untouched.
