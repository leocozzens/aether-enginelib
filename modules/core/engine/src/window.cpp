// Local headers
#include <core/engine/window.hpp>
#include <core/graphics/renderer.hpp>

using namespace Aether;

#define REGISTER_GLFW_CALLBACK(_callback, _setter, ...)                             \
    _setter(                                                                        \
        handle,                                                                     \
        [] (GLFWwindow *handle, auto... args) {                                     \
            WindowContext *ctx = (WindowContext*) glfwGetWindowUserPointer(handle); \
            if(ctx->callbacks.resize != nullptr)                                    \
                ctx->callbacks.resize(ctx, args...);                                \
        }                                                                           \
    )


// Constructor / Destructor

WindowContext::WindowContext(const char *name) : Window(name) {
    register_callbacks();
}

WindowContext::~WindowContext() = default;


Window::Window(const char *name) {
    handle = glfwCreateWindow(1200, 600, name, nullptr, nullptr);
}

Window::~Window() {
    unbind();
    if(handle != nullptr) {
        glfwDestroyWindow(handle);
        handle = nullptr;
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

void Window::swap(void) {
    glfwSwapBuffers(handle);
}
void WindowContext::register_callbacks(void) {
    glfwSetWindowUserPointer(handle, (void*) this);

    REGISTER_GLFW_CALLBACK(resize, glfwSetFramebufferSizeCallback);
}