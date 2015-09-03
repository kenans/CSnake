#include "key.h"
#include "port/port.h"

Dir GetDirection(void) {
  switch (PortGetKey()) {
    case 0: 
      return UP;
    case 1: 
      return DOWN;
    case 2: 
      return LEFT;
    case 3: 
      return RIGHT;
    default:
      // Never get here
      return RIGHT;
  }
}

