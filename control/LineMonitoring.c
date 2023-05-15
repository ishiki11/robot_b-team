#include "ev3api.h"
#include "LineMonitoring.h"
#include "ColorSensor.h"

static int threshold = 20; 

// ラインを検知する
bool is_detexting_line(int thereshold){
  int reflect = get_value();
  if (reflect < threshold) {
    return true;
  } else {
    return false;
  }
}

// ゴールの印を検知する
bool is_detexts_goal_maeker(int thereshold){
  
}