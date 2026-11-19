// External libraries
#include <GL/glcorearb.h>
// Local headers
#include <core/window.hpp>

using namespace Aether;

struct Aether::GraphicsContext {
    PFNGLCLEARPROC clear;
    PFNGLCLEARCOLORPROC clearColor;
};

// Constructor / Destructor

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
    unbind();
    if(ctx != nullptr)
        delete ctx;
    ctx = nullptr;
    if(handle != nullptr)
        glfwDestroyWindow(handle);
    handle = nullptr;
}

// Public methods

bool Window::is_open(void) {
    return !glfwWindowShouldClose(handle);
}

void Window::bind(void) { 
    if(ctx == nullptr) {
        ctx = new GraphicsContext();
        ctx->clear = (PFNGLCLEARPROC) glfwGetProcAddress("glClear");
        ctx->clearColor = (PFNGLCLEARCOLORPROC) glfwGetProcAddress("glClearColor");
    }
    glfwMakeContextCurrent(handle);
}

void Window::unbind(void) {
    glfwMakeContextCurrent(nullptr);
}

void Window::render(void) {
    bind();
    ctx->clearColor(0.0F, 0.0F, 1.0F, 1.0F);
    ctx->clear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(handle);
}