// External libraries
#include <GLFW/glfw3.h>
#include <GL/glcorearb.h>

// Local headers
#include <core/renderer.hpp>

struct Aether::GraphicsContext {
    PFNGLCLEARPROC clear;
    PFNGLCLEARCOLORPROC clearColor;
};

using namespace Aether;

// Constructor / Destructor

Renderer::Renderer(void) {
    load_context();
    init();
}

Renderer::~Renderer() {
    delete ctx;
}

// Public methods

void Renderer::cycle(void) {
    ctx->clear(GL_COLOR_BUFFER_BIT);
}

// Private methods

void Renderer::load_context(void) {
    ctx = new GraphicsContext();
    ctx->clear = (PFNGLCLEARPROC) glfwGetProcAddress("glClear");
    ctx->clearColor = (PFNGLCLEARCOLORPROC) glfwGetProcAddress("glClearColor");
}

void Renderer::init(void) {
    ctx->clearColor(0.0F, 0.0F, 1.0F, 1.0F);
}