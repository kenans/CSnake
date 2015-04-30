#include "game.h"
#include "model/snake.h"
#include "model/smap.h"
#include "model/food.h"
// TODO
//#include "port/port.h"
//#include "view/paint.h"
//#include "controller/key.h"

#define S_INIT_X 6
#define S_INIT_Y 1
#define M_MAX_X  16
#define M_MAX_Y  12

static Snake  *ps;
static Smap   *pm;
static Food   *pf;
//static Paint  *pp;

static void GameOver(void);

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
}
void GameThread(void) {
  Dir dir;
  while (1) {
    // Grow ?
    if (ps->head->x == pf->x &&
        ps->head->y == pf->y) {
      SnakeGrow();
      // TODO
      // Renew a random food
//    FoodRenew(x, y);
    }
    // Move
    // TODO: Key pressed?
//  dir = ...;
    dir = GetKey();
    SnakeTurn(dir);
    SnakeMove();
    // Paint

    // Dead ?
    if (ps->head->x >= pm->max_x ||
        ps->head->y >= pm->max_y ||
        ps->head->x <= 0 ||
        ps->head->y <= 0
        ) {
      GameOver();
      break;
    }
    // Delay
    PortDelay(50);
  }
}
static void GameOver(void) {
}
