#ifndef CONFIG_H
#define CONFIG_H

struct Config {
    bool enableESP;
    bool enableAimBot;
    bool enableTriggerBot;
    bool showHealthBars;
    float espColor[3];
    float healthBarColor[3];
    float maxESPDistance;
    float crosshairThreshold;

    uintptr_t localPlayerTeamAddr;
    uintptr_t localPlayerPosAddr;
    uintptr_t entityBaseAddr;
    uintptr_t entityTeamOffset;
    uintptr_t entityPosOffset;
    uintptr_t entityHealthOffset;
    uintptr_t crosshairOffset;
    uintptr_t aimPitchOffset;
    uintptr_t aimYawOffset;
    int maxEntities;
    int entityOffset;
};

extern Config config;
void loadConfig(const char* filename);

#endif

