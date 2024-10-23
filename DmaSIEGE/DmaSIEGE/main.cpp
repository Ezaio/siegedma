#include "esp.h"
#include "aimbot.h"
#include "triggerbot.h"
#include "config.h"
#include "vmm.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>
#include <iostream>

// Function to set up ImGui
void setupImGui(GLFWwindow* window) {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");
    ImGui::StyleColorsDark();
}

// Function to render the ImGui interface
void renderUI() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGui::Begin("Cheat Settings");
    ImGui::Checkbox("Enable ESP", &config.enableESP);
    ImGui::Checkbox("Enable AimBot", &config.enableAimBot);
    ImGui::Checkbox("Enable TriggerBot", &config.enableTriggerBot);
    ImGui::ColorEdit3("ESP Color", config.espColor);
    ImGui::ColorEdit3("Health Bar Color", config.healthBarColor);
    ImGui::SliderFloat("Max ESP Distance", &config.maxESPDistance, 100.0f, 5000.0f);
    ImGui::SliderFloat("Crosshair Proximity", &config.crosshairThreshold, 1.0f, 100.0f);
    ImGui::End();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

// Main loop for the cheat
int main() {
    // Initialize vmm.dll and check if it loaded successfully
    if (!initializeVMM()) {
        return -1;  // Exit if vmm.dll could not be loaded
    }

    // Load the config.json file
    loadConfig("config.json");

    // Set up OpenGL window and ImGui
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW!" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(1280, 720, "DMA Cheat UI", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window!" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    setupImGui(window);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        // Start cheat rendering logic
        renderESP();     // Render ESP around enemies
        aimBot();        // Visualize AimBot targeting
        triggerBot();    // Check for TriggerBot proximity

        // Render ImGui UI
        renderUI();

        // Swap buffers (OpenGL)
        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
