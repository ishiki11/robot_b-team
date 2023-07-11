#include "ev3api.h"
#include "LineMonitoring.h"
#include "ColorSensor.h"

static int threshold = 30
// ラインを検知する
bool is_detexting_line() {
  int reflect = get_value();
  if (reflect < threshold) {
    // 黒
    return true;
  } else {
    // 白
    return false;
  }
}

// ブルーライン検知（ダブルループに変更）
bool is_detexts_blue_line() {
  int value = get_color();
  if (value == 3) {
    // value = 3 青
    return true;
  } else {
    return false;
  }
}