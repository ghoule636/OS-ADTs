/*
 * Group 3 OS ADTs
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
    int pcb;
	struct Node* next;
} Node;

void enqueue(int theElement);
int dequeue(void);
