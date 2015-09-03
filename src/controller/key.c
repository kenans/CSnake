#include "key.h"
#include "port/port.h"

void KeyInit(void) {
  PortKeyInit();
}

Dir GetDirection(void) {
  static Dir last_dir = RIGHT;
  switch (PortGetKey()) {
    case 0: 
      last_dir = UP;
      return UP;
    case 1: 
      last_dir = DOWN;
      return DOWN;
    case 2: 
      last_dir = LEFT;
      return LEFT;
    case 3: 
      last_dir = RIGHT;
      return RIGHT;
    default:
      return last_dir;
  }
}

