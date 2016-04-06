/*
 * Group 3 OS ADTs
 */

#include <stdio.h>
#include <stdlib.h>
#include "PCB.h"

struct Node {
    PCB_p data;
	struct Node* next;
} Node;

void enqueue(PCB_p theElement);
PCB_p dequeue(void);
