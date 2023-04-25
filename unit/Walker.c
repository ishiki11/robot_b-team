#include "Walker.h"
#include "app.h"

static int forward;
static bool_t isInitialized;
static const motor_port_t left_motor = EV3_PORT_C;
static const motor_port_t right_motor = EV3_PORT_B;
static int l_power = 0;
static int r_power = 0;
void walker_init()
{
    isInitialized = false;
    forward = 30;
}

void walker_reset()
{
    if (isInitialized == false)
    {
        ev3_motor_reset_counts(left_motor);
        ev3_motor_reset_counts(right_motor);
        isInitialized = true;
    }
}

void walker_set_command(int left_power,int right_power){
    l_power = left_power;
    r_power = right_power;
}

void walker_run()
{

        ev3_motor_set_power(left_motor, l_power);
        ev3_motor_set_power(right_motor, l_power);
}

