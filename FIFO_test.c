#include <time.h>
#include "PCB.h"
#include "FIFO.h"

int main() {
	srand(time(NULL));
	int i, random = 10 + (rand() % 21);

	FIFO testFIFO = FIFO_construct();
	FIFO_init(testFIFO);

	PCB_p testPCB = PCB_construct();
    PCB_init(testPCB);

	for (i = 0; i < 5; i++) {
		enqueue(testFIFO, testPCB);
		char * testStr = malloc(10000);
		FIFO_toString(testFIFO, testStr);
		printf("%s\n", testStr);
	}

	FIFO_deconstruct(testFIFO);
}
