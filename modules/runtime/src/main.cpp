#include <core/engine.hpp>

using namespace Aether;

int main(void) {
    Engine aether;
    aether.run();
    return aether.diagnose(std::cout);
}