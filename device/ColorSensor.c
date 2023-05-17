#include "LineMonitoring.h"
static const sensor_port_t color_sensor = EV3_PORT_2;

int get_value() {
  static int reflect = 0;
  static int color_value = 0;

  color_id = ev3_color_sensor_get_color(color_sensor);
  color_value = 0;
  switch(color_id) {
    case BLACK:
      color_value = 1;
      break;
    case WHITE:
      color_value = 2;
      break;
    case RED:
      color_value = 3;
      break;
  }
  
  return color_value;
}