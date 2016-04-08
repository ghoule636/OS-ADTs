/*
 * Group 3 OS ADTs
 */

typedef struct PriorityQ {
  FIFO priority[16];
} PriorityQ;

typedef struct PriorityQ *PQ_p;

PQ_p PQ_construct(void);
void PQ_enqueue(PQ_p, PCB_p);

#ifndef PQ
#define PQ
#include "PriorityQ.c"
#endif