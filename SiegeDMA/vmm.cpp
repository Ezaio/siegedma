#include "vmm.h"

VmmReadFunc vmm_read = nullptr;

bool initializeVMM() {
    HINSTANCE hDLL = LoadLibrary("vmm.dll");
    if (!hDLL) {
        std::cerr << "Failed to load vmm.dll" << std::endl;
        return false;
    }

    vmm_read = (VmmReadFunc)GetProcAddress(hDLL, "vmm_read");
    if (!vmm_read) {
        std::cerr << "Failed to find vmm_read in vmm.dll" << std::endl;
        FreeLibrary(hDLL);
        return false;
    }

    return true;
}
