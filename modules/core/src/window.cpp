// Local headers
#include <core/window.hpp>
#include <core/renderer.hpp>

using namespace Aether;

// Constructor / Destructor

Window::Window(void) { }

Window::Window(const char *name) {
    Create(name);
}

Window::~Window() {
    Destroy();
}

void Window::Create(const char *name) {
    handle = glfwCreateWindow(1200, 600, name, nullptr, nullptr);
    bind();
    glfwSwapInterval(-1);
    renderer = new Renderer();
}

void Window::Destroy(void) {
    unbind();
    if(handle != nullptr) {
        glfwDestroyWindow(handle);
        handle = nullptr;
    }
    if(renderer != nullptr) {
        delete renderer;
        renderer = nullptr;
    }
}

// Public methods

bool Window::is_open(void) {
    return !glfwWindowShouldClose(handle);
}

void Window::bind(void) { 
    glfwMakeContextCurrent(handle);
}

void Window::unbind(void) {
    glfwMakeContextCurrent(nullptr);
}

void Window::render(void) {
    bind();
    renderer->cycle();
    glfwSwapBuffers(handle);
}