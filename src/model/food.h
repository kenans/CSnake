#ifndef _FOOD_H_
#define _FOOD_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct{
  int x;
  int y;
} Food;

Food *FoodInit(int x, int y);
void FoodRenew(int x, int y);

#ifdef __cplusplus
}
#endif
#endif // _FOOD_H_
