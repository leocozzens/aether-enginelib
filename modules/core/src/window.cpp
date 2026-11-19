#include <core/window.hpp>

using namespace Aether;

Window::Window(void) { }

Window::Window(const char *name) {
    Create(name);
}

Window::~Window() {
    Destroy();
}

void Window::Create(const char *name) {
    handle = glfwCreateWindow(800, 800, name, nullptr, nullptr);
    glfwMakeContextCurrent(handle);
}

void Window::Destroy(void) {
    if(handle != nullptr)
        glfwDestroyWindow(handle);
    handle = nullptr;
}