#ifndef WALKER_H
#define WALKER_H
#include "ev3api.h"

void walker_reset();
void walker_init();
void walker_run();
void walker_set_command(int left_power,int right_power);

#endif