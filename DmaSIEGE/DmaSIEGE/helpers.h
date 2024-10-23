#ifndef HELPERS_H
#define HELPERS_H

float calculateDistance(float x1, float y1, float z1, float x2, float y2, float z2);
void calculateAimAngles(float localX, float localY, float localZ, float targetX, float targetY, float targetZ, float& yaw, float& pitch);
bool isCrosshairNearTarget(float crosshairX, float crosshairY, float targetX, float targetY);
void drawAimVisual(float yaw, float pitch);

#endif
