#include "LineMonitoring.h"
static const sensor_port_t color_sensor = EV3_PORT_2;

int get_value() {
  int color_value=ev3_color_sensor_get_color(color_sensor);
  if (color_value==1,color_value=6) {
    return ev3_color_sensor_get_reflect(color_sensor);
  } else if (color_value==5) {
    return 110;
  }
}


/*
黒　1
青　2
緑　3
黄　4
赤　5
白　6
茶　7
*/
