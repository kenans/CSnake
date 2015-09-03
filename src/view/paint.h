#ifndef _PAINT_H_
#define _PAINT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "model/snake.h"
#include "model/smap.h"
#include "model/food.h"

void DrawSnake(Snake *s);
void DrawMap(Smap *m);
void DrawFood(Food *f);

#ifdef __cplusplus
}
#endif

#endif
