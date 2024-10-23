#include "triggerbot.h"
#include "config.h"
#include "helpers.h"
#include "vmm.h"

// TriggerBot function
void triggerBot() {
    if (!config.enableTriggerBot) return;  // Check if TriggerBot is enabled

    float crosshairX = readMemory<float>(config.crosshairOffset);
    float crosshairY = readMemory<float>(config.crosshairOffset + 0x4);

    // Loop through entities
    for (int i = 0; i < config.maxEntities; ++i) {
        uintptr_t entityAddr = config.entityBaseAddr + i * config.entityOffset;
        float entityX = readMemory<float>(entityAddr + config.entityPosOffset);
        float entityY = readMemory<float>(entityAddr + config.entityPosOffset + 0x4);

        if (isCrosshairNearTarget(crosshairX, crosshairY, entityX, entityY)) {
            highlightEntity(entityAddr);  // Visual feedback for manual firing
        }
    }
}
