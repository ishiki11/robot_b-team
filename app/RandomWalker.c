#include "RandomWalker.h"
#include "ScenarioTracer.h"
#include "LineTracer.h"
#include "Starter.h"
#include "SimpleTimer.h"
#include <stdlib.h>
#include <time.h>

typedef enum {
  UNDEFINED,
  WALKING_FOR_START,
  LINE_TRACER,
  SCENARIO_TRACER,
} state_t;

static state_t state = UNDEFINED;
static int random_walker_get_random_time();
static int random_walker_exec_timer_stop();

void random_walker_init() {
  state = UNDEFINED;
  scenario_tracer_init()
  line_tracer_init()
}

// ScenarioTracerとLineTracerを交互に走らせる
void random_walker_run(){
  random_walker_exec_timer_start()
  switch (state) {
  case UNDEFINED:
    state = WALKING_FOR_START;
    break;
  case WALKING_FOR_START:
    state = LINE_TRACER;
    break;
  case LINE_TRACER:
    random_walker_exec_timer_start();
    
    linetracer_run();
    
    break;
  case SCENARIO_TRACER:
    scenario_tracer_run();

  }
  

}

// タイマーをスタートさせる
static int random_walker_exec_timer_start(){

}

// ランダムな時間を生成
static int random_walker_get_random_time(){
  const int min_seconds=2;
  const int max_seconds=5;
  //srand ランダムを使うための元 srand(元となるデータ)
  srand((unsigned int) time(NULL));
  const int difference =max_seconds-min_seconds;
  const int seconds = min_seconds + rand() % difference;
  return seconds;
}

//単位をあわせる
//3 * 1000 / 10 =300
static int random_walker_exec_timer_stop(){
  return random_walker_get_random_time() * 1000 / 10
}