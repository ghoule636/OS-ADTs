#include <time.h>
#include "PCB.h"
#include "FIFO.h"

int main() {
	srand(time(NULL));
	int i, random = 10 + (rand() % 21);

	FIFO testFIFO = FIFO_construct();
	FIFO_init(testFIFO);

	printf("\n\n\nTEST: %d\n\n\n", testFIFO->size);


	PCB_p testPCB = PCB_construct();
    PCB_init(testPCB);

<<<<<<< HEAD
	random = 3; // DELETE THIS, FOR TESTS

	for (i = 0; i < random; i++) {
=======
	for (i = 0; i < 5; i++) {
>>>>>>> master
		enqueue(testFIFO, testPCB);
		char * testStr = malloc(10000);
		FIFO_toString(testFIFO, testStr);
		printf("%s\n", testStr);
	}

	// FIFO_deconstruct(testFIFO);
}
