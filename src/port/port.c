/*
 * port.c
 *
 *  Created on: 2015Äê4ÔÂ28ÈÕ
 *      Author: apple
 */

#include "port.h"

#ifdef __APPLE__
#include "unistd.h"
#include "stdlib.h"
#include "time.h"
void PortDelay(int ms) {
  usleep(ms * 1000);
}
int PortRand(int max) {
  srand(time(NULL) * time(NULL));
  return rand() % max;
}
#endif
