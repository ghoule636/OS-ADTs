/*
 * Group 3 OS ADTs
 * Spring 2016
 * Authors: Gabriel Houle & Edgardo Gutierrez Jr.
 * GitHub: https://github.com/ghoule636/OS-ADTs.git
 */

typedef struct PriorityQ {
  FIFO priority[16];
} PriorityQ;

typedef struct PriorityQ *PQ_p;

PQ_p PQ_construct(void);
void PQ_destruct(PQ_p);
void PQ_enqueue(PQ_p, PCB_p);
PCB_p PQ_dequeue(PQ_p);
void PQ_toString(PQ_p, char*);

#ifndef PQ
#define PQ
#include "PriorityQ.c"
#endif
