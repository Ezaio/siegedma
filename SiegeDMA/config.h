#ifndef CONFIG_H
#define CONFIG_H

struct Config {
    uintptr_t entityBaseAddr;   // Base address of the entity list
    int maxEntities;            // Maximum number of entities
    uintptr_t entityOffset;     // Offset to the next entity in the list
    uintptr_t entityPosOffset;  // Offset to the entity's position in memory
    uintptr_t entityHealthOffset; // Offset to the entity's health
};

extern Config config;  // Extern variable for global access
void loadConfig(const char* filename);  // Function to load the config file

#endif
