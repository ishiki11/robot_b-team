#include "LineMonitoring.h"
static const sensor_port_t color_sensor = EV3_PORT_2;

int get_value() {
  int reflect = ev3_color_sensor_get_reflect(color_sensor);
  return reflect;
}
