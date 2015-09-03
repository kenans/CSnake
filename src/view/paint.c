#include "paint.h"
#include "port/port.h"

static DrawPoint(int x, int y);
static DrawLine(int x1, int y1, int x2, int y2);
static void DrawRefresh(void);

static int max_x_;
static int max_y_;
void DrawInit(int max_x, int max_y) {
  max_x_ = max_x;
  max_y_ = max_y;
  // Attention: x, y should be reversed here!
  PortPaintInit(max_y, max_x);
}
void DrawEnd(void) {
  PortPaintEnd();
}
void DrawClear(void) {
  PortPaintClear();
}
void DrawSnake(Snake *s) {
  SnakeIter it;
  for (it = IterBegin(); it != IterEnd(); it = IterNext(it)) {
    DrawPoint(it->x, it->y);
  }
  DrawRefresh();
}

void DrawMap(Smap *m) {
  DrawLine(0, 0, m->max_x, 0);
  DrawLine(0, 0, 0, m->max_y);
  DrawLine(m->max_x, 0, m->max_x, m->max_y);
  DrawLine(0, m->max_y, m->max_x, m->max_y);
  DrawRefresh();
}

void DrawFood(Food *f) {
  DrawPoint(f->x, f->y);
  DrawRefresh();
}

static DrawPoint(int x, int y) {
  PortPaintPoint(max_y_ - y, x); 
}

static DrawLine(int x1, int y1, int x2, int y2) {
  PortPaintLine(y1, x1, y2, x2);
}
static void DrawRefresh(void) {
  PortRepaint();
}
