/*
 * Group 3 OS ADTs
 * Spring 2016
 * Authors: Gabriel Houle & Edgardo Gutierrez Jr.
 * GitHub: https://github.com/ghoule636/OS-ADTs.git
 */

#include <time.h>
#include "PCB.h"

int main() {
  srand(time(NULL));
  PCB_p test = PCB_construct();
  PCB_init(test);

  char * testStr = malloc(50);
  PCB_toString(test, testStr);
  printf("contents: %s", testStr);

  PCB_set_state(test, ready);
  PCB_set_pid(test, 1);
  PCB_set_priority(test, (rand() % 16));

  PCB_toString(test, testStr);

  printf("contents: %s", testStr);

  PCB_destruct(test);
  free(testStr);

  return 0;
}
