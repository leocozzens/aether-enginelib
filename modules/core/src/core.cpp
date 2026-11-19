#include <iostream>
#include <GLFW/glfw3.h>
#include <core/core.hpp>

GLFWwindow *masterWindowHandle;

void core_init(void) {
    glfwInit();
    glfwSwapInterval(-1);
    masterWindowHandle =
        glfwCreateWindow(800, 800, "AetherEngineTest", nullptr, nullptr);
    glfwMakeContextCurrent(masterWindowHandle);

    // if(masterWindowHandle == nullptr) { we failed }
    while(!glfwWindowShouldClose(masterWindowHandle)) {
        glfwSwapBuffers(masterWindowHandle);
        glfwPollEvents();
    }

    std::cout << "Core initialized!\n";
}

void core_terminate(void) {
    glfwDestroyWindow(masterWindowHandle);
    glfwTerminate();
    std::cout << "Core terimated!\n";
}