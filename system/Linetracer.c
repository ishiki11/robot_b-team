#include "ev3api.h"
#include "LineTracer.h"
#include "Walker.h"

static void calcDirection();
static bool_t isline;

// 初期設定
void linetracer_init() {
  walker_init();
  line_monitor_init();
}

// 走る
void linetracer_run() {
  reset();
  isline = isOnLine();
  calcDirection();
}

// 走行体の向きを決める
static void calcDirection() {
  walker_run(isline);
}