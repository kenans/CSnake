#include <port/port.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  puts("1s waiting...\n");
  PortDelay(1000);
  puts("end\n");
  printf("Rand(5)=%d\n", PortRand(5));
  PortDelay(1000);
  printf("Rand(5)=%d\n", PortRand(5));
  PortDelay(1000);
  printf("Rand(5)=%d\n", PortRand(5));
  PortDelay(1000);
  printf("Rand(5)=%d\n", PortRand(5));
  PortDelay(1000);
  printf("Rand(5)=%d\n", PortRand(5));
  return 0;
}
