// External libraries
#include <GLFW/glfw3.h>
// Local headers
#include <core/display/display.hpp>
#include <core/display/device.hpp>
#include <core/display/renderer.hpp>

using namespace Aether;

// Constructor / Destructor

Display::Display(Window &target) {
    Window::Dimension dim = target.get_dim();
    target.bind();
    glfwSwapInterval(-1);
    active.dev = std::make_shared<DisplayDevice>();
    active.renderer = std::make_unique<DisplayRenderer>(active.dev.get(), dim.width, dim.height);
}

Display::~Display() = default;

// Public methods

void Display::present(void) {
    active.renderer->present();
}

void Display::resize(int width, int height) {
    active.renderer->resize(width, height);
}

void Display::change_device(const std::shared_ptr<DisplayDevice> &dev) {
    this->active.dev = dev;
}