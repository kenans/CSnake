#include "food.h"

Food f;
Food *FoodInit(int x, int y) {
  f.x = x;
  f.y = y;
  return &f;
}
void FoodRenew(int x, int y) {
  f.x = x;
  f.y = y;
}
