#ifndef WALKER_H_
#define WALKER_H_

#include "ev3api.h"

void walker_init();
// デバイスを初期化する
void walker_reset();
// 決定した向きに従って走行する
void walker_run();
void walker_set_command();


#endif