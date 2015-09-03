#include "paint.h"
#include "port/port.h"

static DrawPoint(int x, int y);
static DrawLine(int x1, int y1, int x2, int y2);

void DrawSnake(Snake *s) {
  SnakeIter it;
  for (it = IterBegin(); it != IterEnd(); it = IterNext(it)) {
    DrawPoint(it->x, it->y);
  }
}

void DrawMap(Smap *m) {
  DrawLine(0, 0, m->max_x, 0);
  DrawLine(0, 0, 0, m->max_y);
  DrawLine(m->max_x, 0, m->max_x, m->max_y);
  DrawLine(0, m->max_y, m->max_x, m->max_y);
}

void DrawFood(Food *f) {
  DrawPoint(f->x, f->y);
}

static DrawPoint(int x, int y) {
  PortPaintPoint(x, y); 
}

static DrawLine(int x1, int y1, int x2, int y2) {
  PortPaintLine(x1, y1, x2, y2);
}
