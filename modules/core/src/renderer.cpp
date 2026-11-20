// External libraries
#include <GLFW/glfw3.h>
#include <GL/glcorearb.h>

// Local headers
#include <core/renderer.hpp>

using namespace Aether;

struct Aether::GraphicsContext {
    PFNGLCLEARPROC clear;
    PFNGLCLEARCOLORPROC clearColor;
    PFNGLVIEWPORTPROC viewport;
};

// Constructor / Destructor

Renderer::Renderer(void) {
    load_context();
    init();
}

Renderer::~Renderer() = default;

// Public methods
void Renderer::present(void) {
    ctx->clear(GL_COLOR_BUFFER_BIT);
}

void Renderer::resize(int width, int height) {
    ctx->viewport(0, 0, (GLsizei) width, (GLsizei) height);
}

// Private methods

void Renderer::load_context(void) {
    ctx = std::make_unique<GraphicsContext>();
    ctx->clear = (PFNGLCLEARPROC) glfwGetProcAddress("glClear");
    ctx->clearColor = (PFNGLCLEARCOLORPROC) glfwGetProcAddress("glClearColor");
    ctx->viewport = (PFNGLVIEWPORTPROC) glfwGetProcAddress("glViewport");
}

void Renderer::init(void) {
    ctx->clearColor(0.0F, 0.0F, 1.0F, 1.0F);
}