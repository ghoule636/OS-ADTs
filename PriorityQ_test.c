/*
 * Group 3 OS ADTs
 */

#include "PCB.h"
#include "FIFO.h"
#include "PriorityQ.h"

int main() {
  int i, j;
  PQ_p priorityTest = PQ_construct();
  char * testStr = malloc(50);

  for (i = 1; i <= 2; i++) {
    for (j = 1; j <= 10; j++) {
      PCB_p test = PCB_construct();
      PCB_init(test);
      test->priority = rand() % 16;

      PCB_toString(test, testStr);
      printf("contents: %s\n", testStr);

      PQ_enqueue(priorityTest, test);
    }
    //should print whole q here.
  }

  /*PCB_p test3 = PCB_construct();
  PCB_init(test3);

  char * testStr = malloc(50);
  PCB_toString(test3, testStr);
  printf("contents: %s\n", testStr);

  PQ_enqueue(priorityTest, test3);

  PCB_p test2 = PQ_dequeue(priorityTest);

  PCB_toString(test2, testStr);
  printf("contents: %s\n", testStr);

  PCB_set_state(test2, running);

  PCB_toString(test2, testStr);
  printf("contents: %s\n", testStr);

  PCB_destruct(test3);*/
  free(testStr);

  return 0;
}