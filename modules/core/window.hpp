#ifndef AETHER_WINDOW_HPP
#define AETHER_WINDOW_HPP

#include <GLFW/glfw3.h>

namespace Aether {
    class Window {
        public:
            Window();
            Window(const char *name);
            ~Window();
        public:
            void Create(const char *name);
            void Destroy(void);

            GLFWwindow *handle = nullptr;
        private:
    };
}


#endif