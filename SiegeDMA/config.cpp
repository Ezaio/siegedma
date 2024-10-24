#include "config.h"
#include <fstream>
#include <iostream>
#include "json.hpp"  // Include nlohmann's JSON library (you need to have it in your project)

Config config;

void loadConfig(const char* filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open config.json!" << std::endl;
        return;
    }

    nlohmann::json configJson;
    file >> configJson;

    // Load values from JSON
    config.entityBaseAddr = std::stoul(configJson["entityBaseAddr"], nullptr, 16);
    config.maxEntities = configJson["maxEntities"];
    config.entityOffset = std::stoul(configJson["entityOffset"], nullptr, 16);
    config.entityPosOffset = std::stoul(configJson["entityPosOffset"], nullptr, 16);
    config.entityHealthOffset = std::stoul(configJson["entityHealthOffset"], nullptr, 16);
}
