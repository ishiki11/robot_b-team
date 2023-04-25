#include "app.h"
#include <stdio.h>
#include "ScenarioTracerWithStarter.h"

// センサーポートの定義
static const sensor_port_t color_sensor = EV3_PORT_2;

// モーターポートの定義
static const motor_port_t left_motor = EV3_PORT_C;
static const motor_port_t right_motor = EV3_PORT_B;

/* メインタスクで実行される関数 */
void main_task(intptr_t unused)
{
    // センサーの入力ポートを設定する
    ev3_sensor_config(color_sensor, COLOR_SENSOR);

    // モーターの出力ポートを設定する
    ev3_motor_config(left_motor, MEDIUM_MOTOR);
    ev3_motor_config(right_motor, MEDIUM_MOTOR);

    scenario_tracer_with_starter_init();
    // linetracer_with_starter_init();

    // if (ev3_button_is_pressed(ENTER_BUTTON))
    // {
    // }
    // else
    // {
    // }
    printf("test");
    sta_cyc(TRACER_TASK_CYC);
    slp_tsk();

    stp_cyc(TRACER_TASK_CYC);

    ev3_motor_stop(left_motor, true);
    ev3_motor_stop(right_motor, true);


    // タスクを終了する
    ext_tsk();
}

void tracer_task(intptr_t exinf){
    scenario_tracer_with_starter_run();
}
