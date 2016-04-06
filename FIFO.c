#include "FIFO.h"

FIFO FIFO_construct(void) {
  FIFO result = (struct FIFO*) malloc(sizeof(FIFO));
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

	if(theNode->head == NULL && theNode->tail == NULL){
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
	}
	else if (theNode->head != NULL){
        value = theNode->head->data;
		theNode->head = theNode->head->next;
	}
    return value;
}

// void toString(void) {
//
// }

int main() {

	FIFO myFIFO = FIFO_construct();
	FIFO_init(myFIFO);


	PCB_p test = PCB_construct();
    PCB_init(test);

	enqueue(myFIFO, test);

	PCB_p test2 = dequeue(myFIFO);

	char * testStr = malloc(50);
	PCB_toString(test2, testStr);
	printf("contents: %s", testStr);









}
