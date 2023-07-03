#ifndef MOTOR_H_
#define MOTOR_H_

#include "ev3api.h"

// モータを初期化する
void motor_init();

// モーターの回転量を取得する 
int motor_spin_volume();

// モーターを停止する
void motor_stop();

// モーターを回転させる
void motor_spin(int, int);

#endif