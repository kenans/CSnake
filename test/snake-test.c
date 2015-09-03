#include "model/snake.h"
#include "stdio.h"

void printNode(int x, int y) {
  printf("Node(x, y) = (%d, %d)\n", x, y);
}
int main(int argc, char *argv[]) {
  int x, y;
  int i;
  SnakeIter it;
  Snake *s = SnakeInit(10, 10);
  for (i = 0 ; i < 10; ++i) {
	  x = 13 - i;
	  y = 10;
	  printf("(%d, %d) in snake: %d\n", x, y, InSnake(x, y));
  }
  ForeachSnakeNode(printNode);
  printf("Moved...\n");
  SnakeMove();
  ForeachSnakeNode(printNode);
  printf("Turned DOWN and Moved...\n");
  SnakeTurn(DOWN);
  SnakeMove();
  ForeachSnakeNode(printNode);
  printf("Grown and Moved...\n");
  SnakeGrow();
  SnakeMove();
  ForeachSnakeNode(printNode);
  printf("Iter test...\n");
  for (it = IterBegin(); it != IterEnd(); it = IterNext(it)) {
     printNode(it->x, it->y);
  }
  return 0;
}




