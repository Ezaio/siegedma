#include "helpers.h"
#include <cmath>

// Calculate 3D distance between two points
float calculateDistance(float x1, float y1, float z1, float x2, float y2, float z2) {
    return sqrtf(powf(x2 - x1, 2) + powf(y2 - y1, 2) + powf(z2 - z1, 2));
}

// Calculate the yaw and pitch for AimBot
void calculateAimAngles(float localX, float localY, float localZ, float targetX, float targetY, float targetZ, float& yaw, float& pitch) {
    float deltaX = targetX - localX;
    float deltaY = targetY - localY;
    float deltaZ = targetZ - localZ;
    yaw = atan2f(deltaY, deltaX) * (180.0f / 3.14159265359f);
    pitch = -atan2f(deltaZ, sqrtf(deltaX * deltaX + deltaY * deltaY)) * (180.0f / 3.14159265359f);
}

// Check if crosshair is near a target (TriggerBot logic)
bool isCrosshairNearTarget(float crosshairX, float crosshairY, float targetX, float targetY) {
    return (sqrtf(powf(crosshairX - targetX, 2) + powf(crosshairY - targetY, 2)) < config.crosshairThreshold);
}

// Draw AimBot visual feedback
void drawAimVisual(float yaw, float pitch) {
    // Implement drawing logic for AimBot visual feedback (e.g., draw a line toward the target)
}
