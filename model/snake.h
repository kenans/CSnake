#ifndef _SNAKE_H_
#define _SNAKE_H_

typedef struct Node {
  int x;
  int y;
};
typedef enum Dir {
  UP    = -1,
  DOWN  = 1,
  LEFT  = -2,
  RIGHT = 2
};
typedef struct Snake {
  int len;
  int speed;

  Dir dir;

  Node *head;
  Node *tail;
  Node trace[MAX_LEN];
};

// APIs
Snake *SnakeInit(int x, int y);
void SnakeMove(void);
void SnakeTurn(Dir dir);
void SnakeGrow(void);
#endif // _SNAKE_H_
