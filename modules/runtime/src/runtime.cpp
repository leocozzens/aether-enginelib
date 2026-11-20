// Local headers
#include <runtime/runtime.hpp>
#include <core/engine/engine.hpp>

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
        // engine->process_input
        // engine->step_world
        engine->update();
    }
}

int Runtime::diagnose(const std::ostream &out) {
    return engine->diagnose(out);
}