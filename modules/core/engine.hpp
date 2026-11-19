#ifndef AETHER_ENGINE_HPP
#define AETHER_ENGINE_HPP

#include <core/window.hpp>

namespace Aether {
    class Engine {
        public:
            Engine(void);
            ~Engine();
        public:
        private:
            Window master;
    };
}

#endif