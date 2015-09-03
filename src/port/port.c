/*
 * port.c
 *
 *  Created on: 2015Äê4ÔÂ28ÈÕ
 *      Author: apple
 */

#include "port.h"

#if defined __APPLE__ || __linux__ || __unix__
#include "unistd.h"
#include "stdlib.h"
#include "time.h"
#include "ncurses.h"
static int ParseKey(int ch);
static int max_x_;
static int max_y_;
static void PortPaintVecLine(int x, int y1, int y2);
static void PortPaintHoriLine(int y, int x1, int x2);
void PortDelay(int ms) {
  usleep(ms * 1000);
}
int PortRand(int max) {
  srand(time(NULL) * time(NULL) * max);
  return rand() % max;
}
void PortKeyInit(void) {
  raw(); 
  timeout(0);
}
int PortGetKey(void) {
  //return PortRand(100) % 4;
  timeout(0);
  int ch = getch(); 
  return ParseKey(ch);
}
static int ParseKey(int ch) {
  switch (ch) {
    case 'w':
      return 0;
    case 's':
      return 1;
    case 'a':
      return 2;
    case 'd':
      return 3;
    default:
      return 4;
  }
}
void PortPaintInit(int max_x, int max_y) {
  initscr();
  noecho();
  max_x_ = max_x;
  max_y_ = max_y;
}
void PortPaintPoint(int x, int y) {
  mvprintw(x, 2 * y, "*");
  mvprintw(x, 2 * y + 1, " ");
}
void PortPaintLine(int x1, int y1, int x2, int y2) {
  if (x1 == x2)
    PortPaintVecLine(x1, y1, y2);
  else 
    PortPaintHoriLine(y1, x1, x2);
}
static void PortPaintVecLine(int x, int y1, int y2) {
  while (y1 <= y2) {
    mvprintw(x, 2 * y1, "*");
    y1 += 1;
  }
}
static void PortPaintHoriLine(int y, int x1, int x2) {
  while (x1 <= x2) {
    mvprintw(x1, 2 * y, "*");
    x1 += 1;
  }
}
void PortRepaint(void) {
  mvprintw(max_x_ + 1, 0, "");
  refresh();
}
void PortPaintClear(void) {
  clear();
}
void PortPaintEnd(void) {
  endwin();
}
#elif defined _WIN32
#else
#error "error: undefined system"
#endif
