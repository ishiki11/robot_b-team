#include "ev3api.h"
#include "LineMonitoring.h"
#include "ColorSensor.h"

static int threshold = 2;

// ラインを検知する
bool is_detexting_line(int threshold) {
  int value = get_value();
  if (value < threshold) {
    // value = 1 黒
    return true;
  } else {
    // value = 2 白
    return false;
  }
}

// ゴールの印を検知する
bool is_detexts_goal_marker(int threshold) {
  int value = get_value();
  if (value > threshold) {
    // value = 3 赤
    return true;
  } else {
    return false;
  }
}