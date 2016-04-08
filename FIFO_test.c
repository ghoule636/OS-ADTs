#include "FIFO.c"
int main() {

	FIFO myFIFO = FIFO_construct();
	FIFO_init(myFIFO);

	PCB_p test = PCB_construct();
    PCB_init(test);

	enqueue(myFIFO, test);
    enqueue(myFIFO, test);
    enqueue(myFIFO, test);


	// PCB_p test2 = dequeue(myFIFO);
    //
	// char * testStr = malloc(50);
	// PCB_toString(test2, testStr);
	// printf("contents: %s", testStr);

    char * testStr = malloc(10000);
    FIFO_toString(myFIFO, testStr);
    printf("YO: %s", testStr);
}
