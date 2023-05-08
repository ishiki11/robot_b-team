#ifndef SCENE_H_
#define SCENE_H_

typedef enum {
  GO_STRAIGHT,
  TURN_LEFT,
  TURN_RIGHT,
  STOP,
} command_t;

typedef struct {
  command_t command;
  int time;
  struct scene_tt *next;
} scene_t;

#endif