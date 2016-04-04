/*
 * Group 3 OS ADTs
 */

#include "PCB.h"

int main() {
  PCB_p test = PCB_construct();
  PCB_init(test);
  char * testStr = malloc(50);
  //PCB_toString(test, testStr);

  //printf("contents: %s", testStr);


  PCB_destruct(test);
  free(testStr);
  printf("hello");

  return 0;
}