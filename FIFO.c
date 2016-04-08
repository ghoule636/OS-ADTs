/*
 * Group 3 OS ADTs
 */

#ifndef Q
#define Q
#include "FIFO.h"
#endif

FIFO FIFO_construct(void) {
  FIFO result = (FIFO) malloc(sizeof(FIFO));
  return result;
}

void FIFO_init(FIFO theFIFO) {
	theFIFO->data = NULL;
	theFIFO->head = NULL;
	theFIFO->tail = NULL;
	theFIFO->next = NULL;
}

void enqueue(FIFO theNode, PCB_p theElement) {

	struct Node* temp = (struct Node*) malloc(sizeof(Node));
	FIFO_init(temp);

	temp->data = theElement;

	if(theNode->head == NULL && theNode->tail == NULL) {
		theNode->head = theNode->tail = temp;
		return;
	}
	theNode->tail->next = temp;
	theNode->tail = temp;
}

PCB_p dequeue(FIFO theNode) {
  PCB_p value = NULL; // No value in queue
	if(theNode->head == theNode->tail) {
    value = theNode->head->data;
	  theNode->head = theNode->tail = NULL;
  } else if (theNode->head != NULL) {
    value = theNode->head->data;
	  theNode->head = theNode->head->next;
	}
  return value;
}

// void toString(void) {
//
// }