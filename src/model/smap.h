#ifndef _SMAP_H_
#define _SMAP_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  int max_x;
  int max_y;
} Smap;
Smap *SmapInit(int max_x, int max_y);

#ifdef __cplusplus
}
#endif
#endif // _SMAP_H_
