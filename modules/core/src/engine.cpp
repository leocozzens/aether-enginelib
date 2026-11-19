#include <GLFW/glfw3.h>

#include <core/engine.hpp>
#include <core/window.hpp>

using namespace Aether;

// Constructor / Destructor

Engine::Engine(void) {
    glfwInit();
    master.Create("AetherTestWindow");
    master.bind();
    glfwSwapInterval(-1);
}

Engine::~Engine() {
    master.Destroy();
    glfwTerminate();
}

// Public methods

void Engine::run(void) {
    while(master.is_open()) {
        master.render();
        glfwPollEvents();
    }
}

int Engine::diagnose(std::ostream &out) {
    return 0;
}