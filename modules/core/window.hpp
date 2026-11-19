#ifndef AETHER_WINDOW_HPP
#define AETHER_WINDOW_HPP

#include <GLFW/glfw3.h>

namespace Aether {
    struct GraphicsContext;

    class Window {
        public:
            Window();
            Window(const char *name);
            ~Window();

            void Create(const char *name);
            void Destroy(void);
        public:
            bool is_open(void);
            void bind(void);
            void unbind(void);
            void render(void);

            GLFWwindow *handle = nullptr;
        private:
            GraphicsContext *ctx = nullptr;
    };
}

#endif