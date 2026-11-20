// Local headers
#include <runtime/runtime.hpp>
#include <core/engine.hpp>

using namespace Aether;

// Constructor / Destructor

Runtime::Runtime(void) {
    engine = new Engine();
}

Runtime::~Runtime() {
    delete engine;
}

// Public methods

void Runtime::run(void) {
    while(engine->is_running()) {
        engine->poll();
        engine->master.render();
    }
}

int Runtime::diagnose(const std::ostream &out) {
    return engine->diagnose(out);
}