/*
 * Group 3 OS ADTs
 */

#ifndef PQ
#define PQ
#include "PriorityQ.h"
#endif

PQ_p PQ_construct(void) {
  PQ_p result = malloc(sizeof(PriorityQ));
  int i;
  for (i = 0; i < 16; i++) {

    FIFO myFIFO = FIFO_construct();
    FIFO_init(myFIFO);

    result->priority[i] = myFIFO;
  }

  return result;
}

void PQ_enqueue(PQ_p theQ, PCB_p thePCB) {
  enqueue(theQ->priority[thePCB->priority], thePCB);
}