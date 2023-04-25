#include "ScenarioTracerWithStarter.h"
#include "Starter.h"
#include "ScenarioTracer.h"

typedef enum {
    UNDEFINED,
    INITIALIZE,
    WALKING,
    WAIT_FOR_START
} state_t;

static state_t state = UNDEFINED;

void scenario_tracer_with_starter_init()
{
    state = UNDEFINED;
    starter_init();
    scenario_tracer_init();
}

void scenario_tracer_with_starter_run()
{
    switch (state)
    {
    case UNDEFINED:
        state = WAIT_FOR_START;
        break;
    case WAIT_FOR_START:
        if(starter_is_pushed())
            state = WALKING;
        break;
    case WALKING:
        scenario_tracer_run();
        break;
    default:
        break;
    }
}