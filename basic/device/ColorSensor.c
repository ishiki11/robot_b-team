#include "LineMonitoring.h"
static const sensor_port_t color_sensor = EV3_PORT_2;

int get_value() {
  static int reflect = 0;

  reflect = ev3_color_sensor_get_reflect(sensor_port_t color_sensor)
  
  return reflect;
}