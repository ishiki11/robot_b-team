#include "ScenarioTracer.h"
#include "SimpleTimer.h"
#include "Walker.h"
#include "Scenario.h"
#include "Scene.h"

typedef enum {
  UNDEFINED,
  INITIALIZE,
  WALKING,
} state_t;

static state_t state = UNDEFINED;

static scene_t scenes[] = {
  {TURN_LEFT, 5000/10, 0},    //左旋回5秒
  {GO_STRAIGHT, 2000/10, 0},  //直進2秒
  {TURN_LEFT, 4000/10, 0},    //左旋回4秒
  {GO_STRAIGHT, 3000/10, 0},  //直進3秒
};

void scenario_tracer_init() {
  state = UNDEFINED;
  walker_init();
  simple_timer_init();
  scenario_init();

  for(int i=0; i<(sizeof(scenes) / sizeof(scene_t)); i++) {
    scenario_add_scene(&scenes[i]);
  }
};

void scenario_tracer_run() {
  switch (state) {
  case UNDEFINED:
    state = INITIALIZE;
    break;
  case INITIALIZE:
    walker_reset();
    state = WALKING;
    
    scenario_next_scene();
    walker_set_command(30, 30);
    simple_timer_set_end_time(scenario_get_current_scene_time());
    break;
  default:
    walker_run();
    if( simple_timer_is_end_time() ) {
      simple_timer_stop();
    }
    break;
  }
};