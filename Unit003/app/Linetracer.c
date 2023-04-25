#include "Linetracer.h"
#include "Walker.h"
#include "Linemonitor.h"
#include "Linetracerwithstarter.h"

static void calcDirection();

void linetracer_init()
{
    walker_init();
    line_monitor_init();
}

void linetracer_run()
{
    bool_t isLine;
    reset();
    isLine = isOnLine();
    calcDirection();
}

static void calcDirection()
{
    walker_run(isOnLine);
}