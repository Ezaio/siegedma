#ifndef VMM_H
#define VMM_H

#include <windows.h>
#include <iostream>

typedef BOOL(*VmmReadFunc)(int, uintptr_t, void*, size_t);  // vmm.dll function typedef
extern VmmReadFunc vmm_read;

bool initializeVMM();
template <typename T>
T readMemory(uintptr_t address) {
    T buffer;
    if (!vmm_read(0, address, &buffer, sizeof(T))) {
        std::cerr << "Failed to read memory at address: " << std::hex << address << std::endl;
    }
    return buffer;
}

#endif
