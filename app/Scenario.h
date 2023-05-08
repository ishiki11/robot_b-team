#ifndef SCENARIO_H_
#define SCENARIO_H_

#include "Scene.h"

void scenario_init();
scene_t *scenario_next_scene();
command_t scenario_get_current_scene_command();
int scenario_get_current_scene_time();
void scenario_add_scene(scene_t *scene);

#endif