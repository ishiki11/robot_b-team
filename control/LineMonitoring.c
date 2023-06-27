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

// ブルーライン検知（ダブルループに変更）
bool is_detexts_blue_line(int threshold) {
  int value = get_value();
  if (value > threshold) {
    // value = 3 青
    return true;
  } else {
    return false;
  }
}