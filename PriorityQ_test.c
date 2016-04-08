/*
 * Group 3 OS ADTs
 * Spring 2016
 * Authors: Gabriel Houle & Edgardo Gutierrez Jr.
 * GitHub: https://github.com/ghoule636/OS-ADTs.git
 */

#include <time.h>
#include "PCB.h"
#include "FIFO.h"
#include "PriorityQ.h"

int main() {
  srand(time(NULL));
  int i, j, k;
  PQ_p priorityTest = PQ_construct();
  char * testStr = malloc(50);
  char * testStr2 = malloc(1000);
  k = 0;

  for (i = 1; i <= 10; i++) {
    for (j = 1; j <= 10; j++) {
      PCB_p test = PCB_construct();
      PCB_init(test);
      test->pid = k;
      test->priority = rand() % 16;

      PQ_enqueue(priorityTest, test);
      k++;
    }
    strcpy(testStr2, "");
    PQ_toString(priorityTest, testStr2);
    printf("%s\n\n", testStr2);

    int dequeueCount = 4 + (rand() % 2);
    printf("Enqueue Pause\nDequeueing %d PCBs...\n", dequeueCount);

    for (j = 0; j < dequeueCount; j++) {
      PCB_p removed = PQ_dequeue(priorityTest);
      PCB_toString(removed, testStr);
      printf("%s", testStr);
      PCB_destruct(removed);
    }
    printf("\n\n");
  }
  strcpy(testStr2, "");
  PQ_toString(priorityTest, testStr2);
  printf("%s\n\n", testStr2);

  free(testStr);
  free(testStr2);
  PQ_destruct(priorityTest);
  return 0;
}
