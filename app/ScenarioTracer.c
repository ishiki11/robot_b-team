// #include "ScenarioTracer.h"
// #include "SimpleTimer.h"
// #include "Walker.h"
// #include "Scenario.h"
// #include "Scene.h"



#include "ScenarioTracer.h"
#include "SimpleTimer.h"
#include "Walker.h"
#include "Scenario.h"
#include "Scene.h"

typedef enum {
    UNDEFINED,
    INITIALIZE,
    WALKING
} state_t;
static state_t state = UNDEFINED;
static scene_t scenes[] = {
    {TURN_RIGHT, 5000 / 10, 0},
    {STOP,3000 / 10,0},
};
void scenario_tracer_init()
{
    state = UNDEFINED;
    walker_init();
    simple_timer_init();
    scenario_init();

    for (int i = 0; i < (sizeof(scenes) / sizeof(scene_t)); i++)
    {
        scenario_add_scene(&scenes[i]);
    }
}

void scenario_tracer_run()
{
    // printf("test");
    switch (state)
    {
    case UNDEFINED:
        state = INITIALIZE;
        break;
    case INITIALIZE:
        walker_reset();
        state = WALKING;
        scnario_next_scene();
        // printf("test2");
        switch (scenario_get_current_scene_command())
        {
        case GO_STRAIGHT:
            walker_set_command(60, 60);
            // printf("initialize1");
            break;
        case TURN_RIGHT:
            walker_set_command(10, 60);
            // printf("initialize2");
            break;
        case TURN_LEFT:
            walker_set_command(60, 10);
            // printf("initialize3");
            break;
        case STOP:
            walker_set_command(5, 5);
            // printf("initialize4");
            break;
        default:
            break;
        }
        simple_timer_set_end_time(scenario_get_current_scene_time());
        simple_timer_start();
        // printf("testoooo");
        break;
    case WALKING:
        walker_run();
        if (simple_timer_is_end_time())
        {
            simple_timer_stop();
            scnario_next_scene();
            printf(scnario_next_scene());
            switch (scenario_get_current_scene_command())
            {
            case GO_STRAIGHT:
                walker_set_command(60, 60);
                // printf("walking1");
                break;
            case TURN_RIGHT:
                walker_set_command(10, 60);
                // printf("walking2");
                break;
            case TURN_LEFT:
                walker_set_command(60, 10);
                // printf("walking3");
                break;
            case STOP:
                walker_set_command(5, 5);
                // printf("walking4");
                break;
            default:
                break;
            }
            simple_timer_set_end_time(scenario_get_current_scene_time());
            simple_timer_start();
        }

        break;

    default:
        break;
    }
}

// static state_t state = UNDEFINED;

// static scene_t scenes[] = {
//     {TURN_LEFT, 5000/10,0},     //左旋回5秒
//     {GO_STRAIGHT, 2000/10,0},   //直進2秒
//     {TURN_LEFT, 4000/10,0},     //左旋回4秒
//     {GO_STRAIGHT, 3000/10,0},   //直進3秒
// };

// void scenario_tracer_init()
// {
//     state = UNDEFINED;
//     walker_init();
//     simple_timer_init();
//     scenario_init();

//     for(int i=0; i<(sizeof(scenes)/sizeof(scene_t));i++){
//         scenario_add_scene(&scenes[i]);
//     }
// }

// void scenario_tracer_run()
// {
//     switch (state)
//     {
//     case UNDEFINED:
//         state = INITIALIZE;
//         break;
//     case INITIALIZE:
//         walker_reset();
//         state = WALKING;

//         scenario_get_scene();
//         switch (scenario_get_current_scene_command())
//         {
//         case GO_STRAIGHT:
//             walker_set_command(60,60);
//             break;
//             walker_set_command(90,30);
//             break;
//             walker_set_command(30,90);
//             break;
//             case STOP: walker_set_command(0,0);
//             break;
//         case WALKING:
//             walker_run();
//             if(simple_timer_is_end_time()){
//                 simple_timer_stop();

//                 scenario_next_scene();
//             }
//             walker_set_command(60,60);
//             break;
//             walker_set_command(90,30);
//             break;
//             walker_set_command(30,90);
//             break;
//         }
//         walker_set_command();
//         simple_timer_init(scenario_get_current_scene_time());

