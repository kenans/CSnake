#include "smap.h"

static Smap m;
Smap *SmapInit(int max_x, int max_y) {
  m.max_x = max_x;
  m.max_y = max_y;
  return &m;
}
