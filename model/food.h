#ifndef _FOOD_H_
#define _FOOD_H_

typedef Food {
  int x;
  int y;
};

Food *FoodInit(int x, int y);
void FoodRenew(int x, int y);
#endif // _FOOD_H_
