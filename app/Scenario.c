#include "Scenario.h"

static scene_t *top_scene;
static scene_t *current_scene;

// static void *scenario_get_top_scene; // 不要な行

// 関数の戻り値を修正
static scene_t *scenario_get_top_scene(){
  return top_scene;
}

void scenario_init(){
  top_scene = 0;
  current_scene=0;
}

void scenario_add_scene(scene_t *scene){
  if(top_scene == 0){
    top_scene=scene;
  }else{
    scene_t *s=scenario_get_top_scene();
    while(s->next != scenario_get_top_scene()){
        s=s->next;
    }
    s->next = scene;
  }
  // sが定義されていないので、ここではnextにアクセスできません
  // s->next = scenario_get_top_scene();

  // sceneのnextにアクセスするように修正
  scene->next = scenario_get_top_scene();
}

// 戻り値を修正
scene_t *scenario_next_scene(){
  if(current_scene != 0){
    current_scene = current_scene->next;
  }else{
    current_scene = top_scene;
  }
  return current_scene;
}

// 戻り値を修正
command_t scenario_get_current_scene_command(){
  return current_scene->command;
}

int scenario_get_current_scene_time(){
  return current_scene->time;
}