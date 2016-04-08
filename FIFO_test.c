#include "FIFO.c"
int main() {

	FIFO myFIFO = FIFO_construct();
	FIFO_init(myFIFO);

	PCB_p test = PCB_construct();
    PCB_init(test);


	int random = rand(10, 30);
	int i = 0;

	for (i = 0; i < random; i++) {
		enqueue(myFIFO, test);
		char * testStr = malloc(10000);
		FIFO_toString(myFIFO, testStr);
		printf("%s\n", testStr);
	}

	FIFO_deconstruct(myFIFO);
}
