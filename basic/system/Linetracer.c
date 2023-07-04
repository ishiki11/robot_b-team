#include "LineTracer.h"
#include "Motor.h"
#include "LineMonitoring.h"
#include "DirectionControl.h"
#include "DistanceMonitoring.h"

// デバイスを初期化する
void linetracer_init() {
  motor_init()
}

// 経路に沿って走行する
void running_traced_line() {
  // ラインを検知する
  is_detexting_line()

  // pid操作量を取得する
  float c = get_pid_operating_volume()

  // 走行する向きを計算する
  int b = calculate_travel_direction()

  // 走行した距離を取得する
  int a = obtain_mileage(left,right)

  // カーブかどうか調べる
  bool_t is_curve()

  // 位置による走行速度を取得
  int d = obtain_running_speed(position)
}