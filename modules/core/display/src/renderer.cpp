// External libraries
#include <GLFW/glfw3.h>
// Local headersa
#include <core/display/renderer.hpp>
#include <core/display/device.hpp>

using namespace Aether;

// Constructor / Destructor

DisplayRenderer::DisplayRenderer(DisplayDevice *newDev, int width, int height) {
    dev = newDev;
    dev->clearColor(0.0F, 0.0F, 1.0F, 1.0F);
    resize(width, height);
}

DisplayRenderer::~DisplayRenderer() = default;

// Public methods
void DisplayRenderer::present(void) {
    dev->clear(GL_COLOR_BUFFER_BIT);
}

void DisplayRenderer::resize(int width, int height) {
    dev->viewport(0, 0, (GLsizei) width, (GLsizei) height);
}