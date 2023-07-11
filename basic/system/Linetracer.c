#include "LineTracer.h"
#include "Motor.h"
#include "LineMonitoring.h"
#include "DirectionControl.h"
#include "DistanceMonitoring.h"
#include "ColorSensor.h"


// デバイスを初期化する
void linetracer_init() {
  // モーターの角位置をリセット
  motor_init(); 
}

// 経路に沿って走行する
void running_traced_line() {

  // pid操作量を取得
  float pid[] = get_pid_operating_volume()

  int reflect = get_value();
  // 向きを取得
  int tern = calculate_travel_direction(pid, reflect)
  // 前進のパワーと操作量が100を超えていないか検証する
  if (tern > 60)
  {
    tern = 60;
  }
  if (tern < -60)
  {
    tern = -60;
  }

  if (tern < 0)
  {
    // 右上に前進する
    lpower = 40 - tern;
    rpower = 40;
  }
  else
  {
    // 左上に前進する
    lpower = 40;
    rpower = 40 + tern;
  }

  motor_spin(lpower,rpower)
}