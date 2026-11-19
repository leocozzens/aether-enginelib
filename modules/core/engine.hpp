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
            void poll(void);
            bool is_running(void);
            int  diagnose(std::ostream &out);

            Window master;
        private:
    };
}

#endif