#include "esp.h"
#include "config.h"
#include "vmm.h"
#include <iostream>

int main() {
    // Initialize DMA (vmm.dll)
    if (!initializeVMM()) {
        std::cerr << "Failed to initialize vmm.dll!" << std::endl;
        return -1;
    }

    // Load configuration
    loadConfig("config.json");

    // Main loop
    while (true) {
        renderESP();  // Render ESP around entities
        // Add logic to limit the loop (sleep or frame timing)
    }

    return 0;
}
