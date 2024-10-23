#include "esp.h"
#include "config.h"
#include "vmm.h"
#include "helpers.h"
#include <GL/glut.h>

// ESP rendering function
void renderESP() {
    if (!config.enableESP) return;  // Check if ESP is enabled

    int localPlayerTeam = readMemory<int>(config.localPlayerTeamAddr);

    // Loop through entities
    for (int i = 0; i < config.maxEntities; ++i) {
        uintptr_t entityAddr = config.entityBaseAddr + i * config.entityOffset;
        int entityTeam = readMemory<int>(entityAddr + config.entityTeamOffset);
        if (entityTeam == localPlayerTeam) continue;  // Skip teammates

        float entityX = readMemory<float>(entityAddr + config.entityPosOffset);
        float entityY = readMemory<float>(entityAddr + config.entityPosOffset + 0x4);
        float entityZ = readMemory<float>(entityAddr + config.entityPosOffset + 0x8);
        int entityHealth = readMemory<int>(entityAddr + config.entityHealthOffset);

        float distance = calculateDistance(config.localPlayerPosX, config.localPlayerPosY, config.localPlayerPosZ, entityX, entityY, entityZ);
        if (distance > config.maxESPDistance) continue;  // Skip if too far

        drawOutline(entityX, entityY, 40.0f, 80.0f, config.espColor);
        if (config.showHealthBars) {
            drawHealthBar(entityX, entityY - 10.0f, 50.0f, 5.0f, entityHealth, 100, config.healthBarColor);
        }
    }
}

// Draw outline around entity
void drawOutline(float x, float y, float width, float height, float color[3]) {
    glColor3f(color[0], color[1], color[2]);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x - width / 2, y);
    glVertex2f(x + width / 2, y);
    glVertex2f(x + width / 2, y + height);
    glVertex2f(x - width / 2, y + height);
    glEnd();
}

// Draw health bar
void drawHealthBar(float x, float y, float width, float height, int currentHealth, int maxHealth, float color[3]) {
    float healthPercentage = (float)currentHealth / maxHealth;
    glColor3f(color[0], color[1], color[2]);
    glBegin(GL_QUADS);
    glVertex2f(x - width / 2, y);
    glVertex2f(x - width / 2 + width * healthPercentage, y);
    glVertex2f(x - width / 2 + width * healthPercentage, y + height);
    glVertex2f(x - width / 2, y + height);
    glEnd();
}
