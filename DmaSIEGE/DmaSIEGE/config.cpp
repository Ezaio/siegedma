#include "config.h"
#include "json.hpp"
#include <fstream>
#include <iostream>

Config config;

// Load configuration from a file
void loadConfig(const char* filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open config file!" << std::endl;
        return;
    }

    nlohmann::json configJson;
    file >> configJson;

    // Load settings from JSON
    config.enableESP = configJson["enableESP"];
    config.enableAimBot = configJson["enableAimBot"];
    config.enableTriggerBot = configJson["enableTriggerBot"];
    config.showHealthBars = configJson["showHealthBars"];
    config.espColor[0] = configJson["espColor"][0];
    config.espColor[1] = configJson["espColor"][1];
    config.espColor[2] = configJson["espColor"][2];
    config.healthBarColor[0] = configJson["healthBarColor"][0];
    config.healthBarColor[1] = configJson["healthBarColor"][1];
    config.healthBarColor[2] = configJson["healthBarColor"][2];
    config.maxESPDistance = configJson["maxESPDistance"];
    config.crosshairThreshold = configJson["crosshairThreshold"];

    config.localPlayerTeamAddr = std::stoul(configJson["localPlayerTeamAddr"], nullptr, 16);
    config.localPlayerPosAddr = std::stoul(configJson["localPlayerPosAddr"], nullptr, 16);
    config.entityBaseAddr = std::stoul(configJson["entityBaseAddr"], nullptr, 16);
    config.entityTeamOffset = std::stoul(configJson["entityTeamOffset"], nullptr, 16);
    config.entityPosOffset = std::stoul(configJson["entityPosOffset"], nullptr, 16);
    config.entityHealthOffset = std::stoul(configJson["entityHealthOffset"], nullptr, 16);
    config.crosshairOffset = std::stoul(configJson["crosshairOffset"], nullptr, 16);
    config.aimPitchOffset = std::stoul(configJson["aimPitchOffset"], nullptr, 16);
    config.aimYawOffset = std::stoul(configJson["aimYawOffset"], nullptr, 16);
    config.maxEntities = configJson["maxEntities"];
    config.entityOffset = configJson["entityOffset"];
}
