#include <iostream>
#include <GLFW/glfw3.h>
#include <core/engine.hpp>
#include <core/window.hpp>

using namespace Aether;

Engine::Engine(void) {
    glfwInit();
    glfwSwapInterval(-1);
    master.Create("AetherTestWindow");
    while(!glfwWindowShouldClose(master.handle)) {
        glfwSwapBuffers(master.handle);
        glfwPollEvents();
    }

    std::cout << "Core initialized!\n";
}

Engine::~Engine() {
    glfwDestroyWindow(master.handle);
    glfwTerminate();
    std::cout << "Core terimated!\n";
}