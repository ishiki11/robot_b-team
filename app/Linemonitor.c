#include "Linemonitor.h"

static int threshold;
static const sensor_port_t color_sensor = EV3_PORT_2;

void line_monitor_init()
{
    threshold = 20;
}

bool_t isOnLine()
{
    int refrect = ev3_color_sensor_get_reflect(color_sensor);
    if (refrect < threshold)
    {
        // printf("refrect: %3d\n", refrect);
        return true;
    }
    else
    {
        printf("refrect: %3d\n", refrect);
        return false;
    }
}