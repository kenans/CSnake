#include "game.h"
#include "model/snake.h"
#include "model/smap.h"
#include "model/food.h"
#include "view/paint.h"
#include "controller/key.h"
#include "port/port.h"

#define S_INIT_X 6
#define S_INIT_Y 1
#define M_MAX_X  30
#define M_MAX_Y  18

static Snake  *ps;
static Smap   *pm;
static Food   *pf;

static void GameOver(void);
static int Hit(void);

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
      // Renew a random food
      x = 1 + PortRand(M_MAX_X - 1);
      y = 1 + PortRand(M_MAX_Y - 1);
      while (InSnake(x, y)) {
        x += 1;
        x = x % (M_MAX_X - 1) + 1;
        y += 2; 
        y = y % (M_MAX_Y - 1) + 1;
      }
      FoodRenew(x, y);
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

