// External libraries
#include <GLFW/glfw3.h>
// Local headers
#include <core/engine.hpp>
#include <core/window.hpp>

using namespace Aether;

// Constructor / Destructor

Engine::Engine(void) {
    glfwInit();
    master.Create("AetherTestWindow");
}

Engine::~Engine() {
    master.Destroy();
    glfwTerminate();
}

// Public methods

void Engine::poll(void) {
    glfwPollEvents();
}

bool Engine::is_running(void) {
    return master.is_open();
}

int Engine::diagnose(const std::ostream &out) {
    return 0;
}