#include "stdio.h"

// --------------------------------------------------------
#define MAX_LEN 32
#define INIT_LEN 5
#define INIT_SPEED 1
// --------------------------------------------------------

// --------------------------------------------------------
typedef struct Node {
  int x;
  int y;
};
typedef enum Dir {
  UP,
  DOWN,
  LEFT,
  RIGHT
};
// --------------------------------------------------------
typedef struct Snake {
  int len;
  int speed;
  Dir dir; 
  Node *head;
  Node *tail;
  Node trace[MAX_LEN];
};
static Snake s;

void SnakeInit(int x, int y) {
  int i;
  s.len = INIT_LEN;
  s.speed = INIT_SPEED;
  s.dir = RIGHT;
  s.head = s.trace;
  s.tail = s.trace + s.len;
  for (i = 0; i < s.len; ++i) {
    s.trace[i].x = x - i;
    s.trace[i].y = y - i;
  }
}
void SnakeMove(void) {
  switch (s.dir) {
  case UP:
    break;
  case DOWN:
    break;
  case LEFT:
    break;
  case RIGHT:
    break;
  default:
    break;
  }
}
void SnakeTurn(Dir dir) {
  s.dir = dir;
}
void SnakeGrow(void) {
  ++s.len;
}

// --------------------------------------------------------
typedef struct Food {
  Node pos;
};
// --------------------------------------------------------
typedef struct Map {
  int x_max;
  int y_max;
};

int main(int argc, char *argv[]) {
  SnakeInit();
  while (1) {
    SnakeMove();
  }
  return 0;
}
