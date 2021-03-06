#include "snake.h"

#ifndef TRUE
#define TRUE 1
#endif  // TURE
#ifndef FALSE
#define FALSE 0
#endif  // FALSE
#ifndef BOOL
#define BOOL int
#endif // BOOL

#define MAX_LEN     64
#define INIT_LEN    5
#define INIT_SPEED  1
static Snake s;
static BOOL to_turn = FALSE;
static Dir next_dir = RIGHT;
static BOOL to_grow = FALSE;
static Node trace_[MAX_LEN];

/**
 *  Initialize a snake, head at (x, y)
 */
Snake *SnakeInit(int x, int y) {
  int i;
  s.trace = trace_;
  s.len = INIT_LEN;
  s.speed = INIT_SPEED;
  s.dir = RIGHT;
  s.tail = s.trace;
  s.head = s.trace + s.len - 1;
  /*
   *  s.trace:
   *    0 1 2 3 4 5 6 ... MAX_LEN-1
   *    |           |
   *    tail        head
   *    \____________/
   *          |
   *         len = 7
   *
   *  After growing:
   *    0 1 2 3 4 5 6 ... MAX_LEN-1
   *                |         |
   *               head      tail
   *    ____________/         \__
   *        |
   *       len = 8
   */
  for (i = 0; i < s.len; ++i) {
    s.trace[s.len - 1 - i].x = x - i;
    s.trace[s.len - 1 - i].y = y;
  }
  return &s;
}
void SnakeMove(void) {
  Node temp;
  if (to_turn) {
    s.dir = next_dir;
    to_turn = FALSE;
  }
  if (!to_grow) {
    (s.tail == s.trace + MAX_LEN - 1) ? (s.tail = s.trace) : (++s.tail);
  } else {
    to_grow = FALSE;
  }
  temp = *s.head;
  (s.head == s.trace + MAX_LEN - 1) ? (s.head = s.trace) : (++s.head);
  switch (s.dir) {
  case UP:
    s.head->x = temp.x;
    s.head->y = temp.y + 1;
    break;
  case DOWN:
    s.head->x = temp.x;
    s.head->y = temp.y - 1;
    break;
  case LEFT:
    s.head->x = temp.x - 1;
    s.head->y = temp.y;
    break;
  case RIGHT:
    s.head->x = temp.x + 1;
    s.head->y = temp.y;
    break;
  default:
    break;
  }
}
void SnakeTurn(Dir dir) {
  if ((s.dir + dir) && (s.dir != dir)) {
    next_dir = dir;
    to_turn = TRUE;
  }
}
void SnakeGrow(void) {
  if (s.len + 1 == MAX_LEN)
    return;
  ++s.len;
  to_grow = TRUE;
}

/**
 *  If Node(x, y) in the snake's trace, returns 1;
 */
int InSnake(int x, int y) {
  SnakeIter it;
  for (it = IterBegin(); it != IterEnd(); it = IterNext(it)) {
    if (x == it->x && y == it->y)
      return TRUE;
  }
  return FALSE;
}
/**
 *  For each node of snake, runs call-back function
 */
void ForeachSnakeNode(void (*callback_func)(int, int)) {
  SnakeIter it;
  for (it = IterBegin(); it != IterEnd(); it = IterNext(it)) {
    callback_func(it->x, it->y);
  }
}

/**
 *  Iteration Methods
 */
SnakeIter IterNext(SnakeIter n) {
  n == s.trace ? n = s.trace + MAX_LEN - 1 : n--;
  return n;
}
SnakeIter IterBegin() {
  return s.head;
}
SnakeIter IterEnd() {
  if (s.tail != s.trace)
    return s.tail - 1;
  return s.trace + MAX_LEN - 1;
}

