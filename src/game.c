#include "game.h"
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
  int x, y;
  while (1) {
    // Grow ?
    if (ps->head->x == pf->x &&
        ps->head->y == pf->y) {
      SnakeGrow();
      // Renew a random food
      do {
        x = PortRand(M_MAX_X);
        y = PortRand(M_MAX_Y);
      } while (InSnake(x, y));
      FoodRenew(x, y);
    }
    // Move
    SnakeTurn(GetDirection());
    SnakeMove();
    // Paint
    //DrawMap();
    //DrawSnake();
    //DrawFood();
    // Dead ?
    if (ps->head->x >= pm->max_x ||
        ps->head->y >= pm->max_y ||
        ps->head->x <= 0 ||
        ps->head->y <= 0 ||
        // TODO 
        // What if snake hits itself ??
        ) {
      GameOver();
      break;
    }
    // Delay
    PortDelay(500);
  }
}
static void GameOver(void) {
}
