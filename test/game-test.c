#include <stdio.h>
#if 0
#include "model/snake.h"
#include "model/smap.h"
#include "model/food.h"
#include "view/paint.h"
#include "controller/key.h"
#include "port/port.h"

#define S_INIT_X 6
#define S_INIT_Y 1
#define M_MAX_X  16
#define M_MAX_Y  12

static Snake  *ps;
static Smap   *pm;
static Food   *pf;

static void GameOver(void);
static int Hit(void);
void PaintNode(int x, int y) {
  printf("(x, y)=(%d, %d)\n", x, y);
}

void GameInit(void) {
  ps = SnakeInit(
        S_INIT_X,
        S_INIT_Y);
  pm = SmapInit(
        M_MAX_X,
        M_MAX_Y);
  pf = FoodInit(
        M_MAX_X/2,
        M_MAX_Y/2);
  KeyInit();
  DrawInit(M_MAX_X, M_MAX_Y);
  //puts("Game start...");
}
void GameThread(void) {
  int x, y;
  Dir dir;
  while (1) {
    // Move
    dir = GetDirection();
    SnakeTurn(dir);
    SnakeMove();
    // Grow ?
    if (ps->head->x == pf->x &&
        ps->head->y == pf->y) {
      SnakeGrow();
      //puts("Hit food, snake grown");
      // Renew a random food
      do {
        x = 1 + PortRand(M_MAX_X - 1);
        y = 1 + PortRand(M_MAX_Y - 1);
      } while (InSnake(x, y));
      FoodRenew(x, y);
      printf("Food renewed at (%d, %d)\n", x, y);
    }
    // Dead ?
    if (Hit()) {
      GameOver();
      break;
    }
    // Paint
    DrawClear();
    DrawMap(pm);
    DrawSnake(ps);
    DrawFood(pf);
    // Delay
    PortDelay(100);
  }
}
static void GameOver(void) {
  //puts("Gameover");
  DrawEnd();
}
static int Hit(void) {
  SnakeIter it;
  if (ps->head->x >= pm->max_x ||
      ps->head->y >= pm->max_y ||
      ps->head->x <= 0 ||
      ps->head->y <= 0
     ) {
    return 1;
  }
  for (it = IterNext(IterBegin()); it != IterEnd(); it = IterNext(it))
    if (it->x == ps->head->x && it->y == ps->head->y)
      return 2;
  return 0;
}
#else
#include "game.h"
#endif

int main() {
  GameInit();
  GameThread();

  return 0;
}
