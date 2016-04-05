#include "FIFO.h"

struct Node* head = NULL;
struct Node* tail = NULL;

void enqueue(int theElement) {
	struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
	temp->data = theElement;
	temp->next = NULL;
	if(head == NULL && tail == NULL){
		head = tail = temp;
		return;
	}
	tail->next = temp;
	tail = temp;
}

int dequeue(void) {
    int value = -100; // No value in queue
	if(head == tail) {
        value = head->pcb;
		head = tail = NULL;
	}
	else {
        value = head->pcb;
		head = head->next;
	}
    return value;
}

// int get_head(void) {
// 	if(head == NULL) {
// 		printf("Queue is empty\n");
// 		return -1;
// 	}
// 	return head->data;
// }

void Print(void) {
	struct Node* temp = head;
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main(){
	enqueue(2); Print();
	enqueue(4); Print();
	enqueue(6); Print();
	dequeue();  Print();
	enqueue(8); Print();
}
