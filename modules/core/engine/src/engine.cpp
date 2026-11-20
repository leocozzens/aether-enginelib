// External libraries
#include <GLFW/glfw3.h>
// Local headers
#include <core/engine/engine.hpp>
#include <core/engine/window.hpp>
#include <core/graphics/renderer.hpp>

using namespace Aether;

// Constructor / Destructor

Engine::Engine(void) {
    glfwInit();

    master.emplace("AetherTestWindow");
    set_default_callbacks(master->callbacks);

    master->bind();
    master->activeRenderer = std::make_shared<Renderer>();
    glfwSwapInterval(-1);
}

Engine::~Engine() {
    master.reset();
    glfwTerminate();
}

// Public methods

void Engine::poll(void) {
    glfwPollEvents();
}

void Engine::update(void) {
    master->bind();
    master->activeRenderer->present();
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
        ctx->activeRenderer->resize(width, height);
        ctx->activeRenderer->present();
        ctx->swap();
    };
}