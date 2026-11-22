// External libraries
#include <GLFW/glfw3.h>
// Local headers
#include <core/engine/engine.hpp>
#include <core/engine/window.hpp>
#include <core/display/display.hpp>

using namespace Aether;

// Constructor / Destructor

Engine::Engine(void) {
    glfwInit();

    master.emplace("AetherTestWindow");
    set_default_callbacks(master->callbacks);
    masterDisplay.emplace(*master);
    master->display = &(*masterDisplay);
}

Engine::~Engine() {
    masterDisplay.reset();
    master.reset();
    glfwTerminate();
}

// Public methods

void Engine::poll(void) {
    glfwPollEvents();
}

void Engine::update(void) {
    master->bind();
    master->display->present();
    master->swap();
}

bool Engine::is_running(void) {
    return master->is_open();
}

int Engine::diagnose(const std::ostream &out) {
    return 0;
}

// Private methods

void Engine::set_default_callbacks(WindowCallbacks &callbacks) {
    callbacks.resize = [] (WindowContext *ctx, int width, int height) {
        ctx->display->resize(width, height);
        ctx->display->present();
        ctx->swap();
    };
}