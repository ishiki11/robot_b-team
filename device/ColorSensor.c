#include "LineMonitoring.h"
static const sensor_port_t color_sensor = EV3_PORT_2;

int get_value() {
  static int color_value = 0;

  color_id = ev3_color_sensor_get_color(color_sensor);
  color_value = 0;
  switch(color_id) {
    case COLOR_BLACK:
      color_value = 1;
      break;
    case COLOR_WHITE:
      color_value = 2;
      break;
    case COLOR_BLUE:
      color_value = 3;
      break;
  }
  
  return color_value;
}