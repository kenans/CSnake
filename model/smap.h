#ifndef _SMAP_H_
#define _SMAP_H_

typedef struct {
  int max_x;
  int max_y;
} Smap;
Smap *SmapInit(int max_x, int max_y);
#endif // _SMAP_H_
