#ifndef SCENARIO_H
#define SCENARIO_H

#include "Scene.h"

void scenario_init();
scene_t *scenario_get_scene();
scene_t *scnario_next_scene();
command_t scenario_get_current_scene_command();
int scenario_get_current_scene_time();
void scenario_add_scene(scene_t *scene);

#endif