#include "DistanceMonitoring.h"

static int left_turn_volume;
static int right_turn_volume;


// 回転量=回転角度



int obtain_mileage(left_turn_volume,right_turn_volume)
{
  // distance4msは移動距離
  int left,right,distance4ms;

  left = ((3.141592 * 10) / 360) * (left_turn_volume - pre_angle);
  right = ((3.141592 * 10) / 360) * (right_turn_volume - pre_angle);
  distance4ms = (left + right) / 2;
  distance += distance4ms;
}


bool_t is_curve()
{

}

int obtain_running_speed(position)
{

}