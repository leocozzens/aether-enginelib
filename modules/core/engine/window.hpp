#ifndef AETHER_ENGINE_WINDOW_HPP
#define AETHER_ENGINE_WINDOW_HPP

#include <GLFW/glfw3.h>

namespace Aether {
    class WindowContext;
    class DisplayRenderer;
    class Display;

    class Window {
        public:
            Window(const char *name);
            ~Window();
        public:
            struct Dimension {
                union {
                    int width, x;
                };
                union {
                    int height, y;
                };
            };
        
            bool is_open(void);
            void bind(void);
            void unbind(void);
            void swap(void);
            Dimension get_dim(void);
    
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
            Display *display;
        private:
            void register_callbacks(void);
    };
}

#endif