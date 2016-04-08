/*
 * Group 3 OS ADTs
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    PCB_p data;
	struct Node* next;
} Node;

typedef struct FIFO {
    struct Node* head;
    struct Node* tail;
    int size;
} *FIFO;

FIFO FIFO_construct(void);
void FIFO_init(FIFO theFIFO);

void enqueue(FIFO theNode, PCB_p theElement);
PCB_p dequeue(FIFO theNode);

#ifndef Q
#define Q
#include "FIFO.c"
#endif
