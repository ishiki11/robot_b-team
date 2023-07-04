#include "LineTracer.h"
#include "Motor.h"
#include "LineMonitoring.h"
#include "DirectionControl.h"
#include "DistanceMonitoring.h"

static bool_t isline

// デバイスを初期化する
void linetracer_init() {
  // モーターの角位置をリセット
  motor_init(); 
}

// 経路に沿って走行する
void running_traced_line() {
  // ライン上かどうか
  isline = is_detexting_line()

  // pid操作量を取得
  float pid = get_pid_operating_volume()
  // 向きを取得
  int direction = calculate_travel_direction(pid)

  if (isline) {
    // 黒の時
    motor_spin(40,30)
  } else {
    // 白の時
    motor_spin(30,40)
  }
}