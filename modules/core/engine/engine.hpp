#ifndef AETHER_ENGINE_HPP
#define AETHER_ENGINE_HPP

#include <iosfwd>
#include <optional>

#include <core/engine/window.hpp>
#include <core/display/display.hpp>
// #include <core/world/scene.hpp>

namespace Aether {
    class Engine {
        public:
            Engine(void);
            ~Engine();
        public:
            void poll(void);
            void update(void);
            bool is_running(void);
            int  diagnose(const std::ostream &out);
        private:
            static void set_default_callbacks(WindowCallbacks &callbacks);

            std::optional<WindowContext> master;
            std::optional<Display> masterDisplay;
            // std::optional<Scene> gameScene;
    };
}

#endif