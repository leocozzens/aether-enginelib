#ifndef AETHER_ENGINE_HPP
#define AETHER_ENGINE_HPP

#include <iostream>

#include <core/window.hpp>

namespace Aether {
    class Engine {
        public:
            Engine(void);
            ~Engine();
        public:
            void run(void);
            int  diagnose(std::ostream &out);
        private:
            Window master;
    };
}

#endif