// Local headers
#include <runtime/runtime.hpp>

using namespace Aether;

int main(void) {
    Runtime aether;
    aether.run();
    return aether.diagnose(std::cout);
}