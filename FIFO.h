/*
 * Group 3 OS ADTs
 */

typedef struct Node {
    PCB_p data;
    struct Node* head;
    struct Node* tail;
	  struct Node* next;
} Node;

typedef struct Node *FIFO;

FIFO FIFO_construct(void);
void FIFO_init(FIFO theFIFO);

void enqueue(FIFO theNode, PCB_p theElement);
PCB_p dequeue(FIFO theNode);

#ifndef Q
#define Q
#include "FIFO.c"
#endif