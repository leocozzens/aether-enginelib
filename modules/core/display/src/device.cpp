// External headers
#include <GLFW/glfw3.h>
// Local headers
#include <core/display/device.hpp>

using namespace Aether;

// Constructor / Destructor

DisplayDevice::DisplayDevice(void) {
    clear = (PFNGLCLEARPROC) glfwGetProcAddress("glClear");
    clearColor = (PFNGLCLEARCOLORPROC) glfwGetProcAddress("glClearColor");
    viewport = (PFNGLVIEWPORTPROC) glfwGetProcAddress("glViewport");
}

DisplayDevice::~DisplayDevice() = default;