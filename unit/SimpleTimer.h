#ifndef SIMPLETIMER_H_
#define SIMPLETIMER_H_

#include "ev3api.h"

void simple_timer_init();
void simple_timer_start();
void simple_timer_set_end_time(int time);
bool_t simple_timer_is_end_time();
void simple_timer_stop();

#endif