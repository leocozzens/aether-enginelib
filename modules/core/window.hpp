#ifndef AETHER_WINDOW_HPP
#define AETHER_WINDOW_HPP

#include <memory>

#include <GLFW/glfw3.h>

namespace Aether {
    class WindowContext;
    class Renderer;

    class Window {
        public:
            Window(const char *name);
            ~Window();
        public:
            bool is_open(void);
            void bind(void);
            void unbind(void);
            void swap(void);
    
            GLFWwindow *handle = nullptr;
        protected:
    };

    struct WindowCallbacks {
        void (*resize)(WindowContext*, int, int) = nullptr;
    };

    class WindowContext : public Window {
        public:
            WindowContext(const char *name);
            ~WindowContext();
        public:
            WindowCallbacks callbacks;
            std::shared_ptr<Renderer> activeRenderer;
        private:
            void register_callbacks(void);
    };
}

#endif