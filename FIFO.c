#include "FIFO.h"

struct Node* head = NULL;
struct Node* tail = NULL;

void enqueue(PCB_p theElement) {
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

PCB_p dequeue(void) {
    int value = NULL; // No value in queue
	if(head == tail) {
        value = head->data;
		head = tail = NULL;
	}
	else {
        value = head->data;
		head = head->next;
	}
    return value;
}

// void Print(void) {
// 	struct Node* temp = head;
// 	while(temp != NULL) {
// 		printf("%d ",temp->data);
// 		temp = temp->next;
// 	}
// 	printf("\n");
// }

int main() {

	PCB_p test = PCB_construct();
	PCB_init(test);


	enqueue(test);

	PCB_p test2 = dequeue();

	char * testStr = malloc(50);
	PCB_toString(test, testStr);
	printf("contents: %s", testStr);





}
