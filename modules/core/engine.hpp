#ifndef AETHER_ENGINE_HPP
#define AETHER_ENGINE_HPP

#include <iosfwd>
#include <optional>

#include <core/window.hpp>

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
    };
}

#endif