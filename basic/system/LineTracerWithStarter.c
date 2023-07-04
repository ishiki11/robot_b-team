#include "LineTracerWithStarter.h"
#include "LineTracer.h"
#include "Starter.h"

typedef enum {
  UNDEFINED,
  WALKING_FOR_START,
  WALKING,
} State_t;
static State_t state;

void linetracer_with_starter_init() {
  state = UNDEFINED;
  linetracer_init();
  starter_init();
}

void linetracer_with_starter_run() {
  switch (state) {
    case UNDEFINED:
      state = WALKING_FOR_START; break;
    case WALKING_FOR_START:
      if(starter_is_pushed())
      {
        state = WALKING;
      }
      break;
    case WALKING:
      linetracer_run();
      break;
    default:
      break;
  }
}