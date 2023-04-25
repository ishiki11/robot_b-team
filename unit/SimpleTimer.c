#include "SimpleTimer.h"

static int start_time;
static int current_time;    //現在の時間
static int end_time;        //指定時間
static bool_t is_started;   //動作の有無

void simple_timer_init()
{
    current_time = 0;
    end_time = 0;
    is_started = false;
}

void simple_timer_start()
{
    if(is_started == false)
    {
        is_started = true;
        current_time = 0;
    }
}

void simple_timer_set_end_time(int time)
{
    if(is_started == false){
        end_time = time;
    }
}

bool_t simple_timer_is_end_time()
{
    if(is_started == true){
        current_time ++;
        if(end_time < current_time){
            return true;
        }
    }
    return false;
}

void simple_timer_stop()
{
    if(is_started == true)
    {
        is_started = false;
    }
}
