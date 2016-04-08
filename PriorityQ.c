/*
 * Group 3 OS ADTs
 */

#ifndef PQ
#define PQ
#include "PriorityQ.h"
#endif

unsigned short MAX_PRIORITIES = 16;

PQ_p PQ_construct(void) {
  PQ_p result = malloc(sizeof(PriorityQ));
  int i;
  for (i = 0; i < MAX_PRIORITIES; i++) {

    FIFO myFIFO = FIFO_construct();
    FIFO_init(myFIFO);

    result->priority[i] = myFIFO;
  }

  return result;
}

void PQ_enqueue(PQ_p theQ, PCB_p thePCB) {
  enqueue(theQ->priority[thePCB->priority], thePCB);
}

PCB_p PQ_dequeue(PQ_p theQ) {
  printf("Hello!\n");
  int i;
  int end = 0;
  PCB_p result = NULL;
  for (i = 0; i < MAX_PRIORITIES && !end; i++) {
    printf("looping %d\n", i);
    if (theQ->priority[i]->head) {
      result = dequeue(theQ->priority[i]);
      end = 1;
    }
  }
  return result;
}

void toString(PQ_p theQ) {

}