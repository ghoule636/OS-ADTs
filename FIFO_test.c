/*
* Group 3 OS ADTs
*/

#include <time.h>
#include "PCB.h"
#include "FIFO.h"

int main() {
	srand(time(NULL));
	int i, random = 10 + (rand() % 21);

	FIFO testFIFO = FIFO_construct();
	FIFO_init(testFIFO);

 	char * testStr = malloc(1000);
 	char * pcbString = malloc(50);

	for (i = 1; i <= random; i++) {
    	PCB_p testPCB = PCB_construct();
    	PCB_init(testPCB);

    	PCB_set_pid(testPCB, i);
    	PCB_set_priority(testPCB, rand() % 16);
		enqueue(testFIFO, testPCB);
		FIFO_toString(testFIFO, testStr);
		printf("Q:%s ", testStr);

    	PCB_toString(testPCB, pcbString);
    	printf("%s\n", pcbString);
	}

	for (i = 1; i < random; i++) {
		PCB_p testPCB = dequeue(testFIFO);
		FIFO_toString(testFIFO, testStr);
		printf("Q:%s ", testStr);

		PCB_toString(testPCB, pcbString);
    	printf("%s\n", pcbString);
    	PCB_destruct(testPCB);
	}
	free(testStr);
	free(pcbString);
	FIFO_deconstruct(testFIFO);
	return 0;
}
