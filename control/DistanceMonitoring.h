#ifndef LINE_MONITOR_H
#define LINE_MONITOR_H

#include "ev3api.h"
#include <stdio.h>

int obtain_mileage(left,right);
bool_t is_curve();
int obtain_running_speed(position);

#endif