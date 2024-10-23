#ifndef VMM_H
#define VMM_H

#include <windows.h>
#include <iostream>

// Typedef for the function pointer to the vmm_read function from vmm.dll
typedef BOOL(*VmmReadFunc)(int, uintptr_t, void*, size_t);

// Global function pointer for vmm_read
extern VmmReadFunc vmm_read;

// Function to load vmm.dll and set up vmm_read
bool initializeVMM();

// Function to read memory using vmm.dll
template <typename T>
T readMemory(uintptr_t address) {
    T buffer;
    if (!vmm_read(0, address, &buffer, sizeof(T))) {
        std::cerr << "Failed to read memory!" << std::endl;
    }
    return buffer;
}

#endif
