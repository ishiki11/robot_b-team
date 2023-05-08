#include "app.h"
#include <stdio.h>
#include "RandomWalker.h"

// センサーポートの定義
static const sensor_port_t color_sensor = EV3_PORT_2;
// モーターポートの定義
static const motor_port_t left_motor = EV3_PORT_C;
static const motor_port_t right_motor = EV3_PORT_B;

/* メインタスクで実行される関数 */
void main_task(intptr_t exinf)
{
  /* センサー入力ポートの設定 */
  ev3_sensor_config(color_sensor ,COLOR_SENSOR);
  /* モーター出力ポートの設定 */
  ev3_motor_config(left_motor    ,MEDIUM_MOTOR);
  ev3_motor_config(right_motor   ,MEDIUM_MOTOR);
    
  random_walker_init()
  
  sta_cyc(LINE_TRACER_TASK_CYC);
  // タスクを終了する
  ext_tsk();

  stp_cyc(LINE_TRACER_TASK_CYC);
}

void run_task() {
  if(ev3_button_is_pressed(RIGHT_BUTTON)) {
    wup_tsk(MAIN_TASK);
  }
  random_walker_run();
}