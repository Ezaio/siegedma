#include "aimbot.h"
#include "config.h"
#include "helpers.h"
#include "vmm.h"

// AimBot function
void aimBot() {
    if (!config.enableAimBot) return;  // Check if AimBot is enabled

    float bestYaw = 0.0f, bestPitch = 0.0f;
    float closestDistance = config.maxESPDistance;

    // Get local player's position
    float localX = readMemory<float>(config.localPlayerPosAddr);
    float localY = readMemory<float>(config.localPlayerPosAddr + 0x4);
    float localZ = readMemory<float>(config.localPlayerPosAddr + 0x8);

    // Loop through all entities
    for (int i = 0; i < config.maxEntities; ++i) {
        uintptr_t entityAddr = config.entityBaseAddr + i * config.entityOffset;
        float entityX = readMemory<float>(entityAddr + config.entityPosOffset);
        float entityY = readMemory<float>(entityAddr + config.entityPosOffset + 0x4);
        float entityZ = readMemory<float>(entityAddr + config.entityPosOffset + 0x8);

        // Calculate distance to entity
        float distance = calculateDistance(localX, localY, localZ, entityX, entityY, entityZ);
        if (distance < closestDistance) {
            closestDistance = distance;
            calculateAimAngles(localX, localY, localZ, entityX, entityY, entityZ, bestYaw, bestPitch);
        }
    }

    // Visual feedback for AimBot (draw a visual indicator)
    drawAimVisual(bestYaw, bestPitch);
}
