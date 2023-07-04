#include "Starter.h"

void starter_init(){
}

bool_t starter_is_pushed()
{
  return ev3_button_is_pressed(LEFT_BUTTON);
}