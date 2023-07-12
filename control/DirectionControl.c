#include "ev3api.h"
#include "DirectionControl.h"

static float pid_value[3];

float get_pid_operating_volume() {
  // pid操作量を取得する処理を記述する
  pid_value[0] = 1.2; //p
  pid_value[1] = 1.3; //i
  pid_value[2] = 1.4; //d
  return pid_value;
}

int calculate_travel_direction(float pid_value) {
  // 走行する向きを計算する処理を記述する
  kp = pid_value[0];
  ki = pid_value[1];
  kd = pid_value[2];

  diff[0] = diff[1];
  diff[1] = /*偏差を取得するための情報がありません※引数*/;
  delta = 0.003;
  integtal += (diff[1] + diff[0]) /2.0 * delta;

  p = kp * diff[1];
  i = ki * integral;
  d = kd * (diff[1] - diff[0])/delta;

  return math_limit(p+i+d,-100.0,100.0);
}
