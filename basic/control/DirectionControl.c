#include "ev3api.h"
#include "DirectionControl.h"

static float pid_value[3];
// 閾値
static const int threshold = (4 + 60) / 2;
static int integral = 0;

float get_pid_operating_volume() {
  // pid操作量を取得する処理を記述する
  pid_value[0] = 1.2; //p
  pid_value[1] = 1.3; //i
  pid_value[2] = 1.4; //d
  return pid_value;
}

int calculate_travel_direction(float pid_value, int reflect) {
  static float diff[2] = {0,0};
  // 走行する向きを計算する処理を記述する
  int kp = pid_value[0]; 
  int ki = pid_value[1]; 
  int kd = pid_value[2]; 

  diff[0] = diff[1];  // 偏差を求める
  diff[1] = (threshold - reflect) // 偏差を取得するための情報がありません※引数
  float delta = 0.003;  // 周期時間
  integral += (diff[1] + diff[0]) / 2.0 * delta; // 

  int p = kp * diff[1]; //P制御の操作量
  int i = ki * integral; //I制御の操作量
  int d = kd * (diff[1] - diff[0])/delta; //D制御の操作量

  return math_limit(p+i+d,-100.0,100.0);
}