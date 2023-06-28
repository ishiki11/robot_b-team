#ifndef LINE_TRACER_H_
#define LINE_TRACER_H_

#include "ev3api.h"

/* 公開の関数宣言 */
// デバイスを初期化する
void linetracer_init();
// 経路に沿って走行する
void running_traced_line();

#endif