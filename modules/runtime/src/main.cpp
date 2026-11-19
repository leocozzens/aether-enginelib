// Local headers
#include <core/engine.hpp>

using namespace Aether;

int main(void) {
    Engine aether;
    while(aether.is_running()) {
        aether.master.render();
        aether.poll();
    }
    return aether.diagnose(std::cout);
}