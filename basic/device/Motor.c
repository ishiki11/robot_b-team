#include "LineTracer.h"
#include "Motor.h"

// モーターポートの定義
static const motor_port_t left_motor = EV3_PORT_C;
static const motor_port_t right_motor = EV3_PORT_B;

// モータを初期化する
void motor_init() {
  // 角位置の初期化
  ev3_motor_reset_counts(left_motor)
  ev3_motor_reset_counts(right_motor)
};

// モーターの回転量を取得する 
int motor_spin_volume() {
  return ev3_motor_get_counts(left_motor) + ev3_motor_get_counts(right_motor)
};

// モーターを停止する
void motor_stop() {
  ev3_motor_stop(left_motor, true)
  ev3_motor_stop(right_motor, true)
};

// モーターを回転させる
void motor_spin(left_power, right_power) {
  ev3_motor_set_power(left_motor, left_power)
  ev3_motor_set_power(right_motor, right_power)
};
