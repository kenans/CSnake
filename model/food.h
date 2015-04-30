#ifndef _FOOD_H_
#define _FOOD_H_

typedef struct{
  int x;
  int y;
} Food;

Food *FoodInit(int x, int y);
void FoodRenew(int x, int y);
#endif // _FOOD_H_
