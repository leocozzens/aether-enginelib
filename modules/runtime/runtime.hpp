#ifndef AETHER_RUNTIME_HPP
#define AETHER_RUNTIME_HPP

#include <iostream>

namespace Aether {
    class Engine;

    class Runtime {
        public:
            Runtime(void);
            ~Runtime();
        public:
            void run(void);
            int diagnose(const std::ostream &out);
        private:
            Engine *engine;
    };
}

#endif