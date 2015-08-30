#ifndef _SNAKE_H_
#define _SNAKE_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  int x;
  int y;
} Node;
typedef enum {
  UP    = -1,
  DOWN  = 1,
  LEFT  = -2,
  RIGHT = 2
} Dir;
typedef struct {
  int len;
  int speed;

  Dir dir;

  Node *head;
  Node *tail;
  Node *trace;
} Snake;

// APIs
Snake *SnakeInit(int x, int y);
void SnakeMove(void);
void SnakeTurn(Dir dir);
void SnakeGrow(void);
int InSnake(int x, int y);
void ForeachSnakeNode(void (*callback_func)(int, int));

#ifdef __cplusplus
}
#endif
#endif // _SNAKE_H_
