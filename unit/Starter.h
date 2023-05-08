#ifndef STARTER_H_
#define STARTER_H_

#include "ev3api.h"

/* 公開の関数宣言 */
void starter_init();
// 走る
bool_t starter_is_pushed();

#endif