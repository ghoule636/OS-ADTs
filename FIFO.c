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

void FIFO_deconstruct(FIFO theFIFO) {
    if (theFIFO) {
        free(theFIFO);
    }
}

void FIFO_init(FIFO theFIFO) {
    theFIFO->head = NULL;
    theFIFO->tail = NULL;
    theFIFO->size = 0;
}

void enqueue(FIFO theFIFO, PCB_p theElement) {
    theFIFO->size = theFIFO->size + 1;
	struct Node* temp = (struct Node*) malloc(sizeof(Node));
	temp->data = theElement;
    printf("THE FUCK %d?\n", theFIFO->size);

    temp->next = NULL;
	if(theFIFO->head == NULL && theFIFO->tail == NULL){
		theFIFO->head = theFIFO->tail = temp;
		return;
	}
	theFIFO->tail->next = temp;
	theFIFO->tail = temp;
}


PCB_p dequeue(FIFO theFIFO) {
    PCB_p value = NULL; // No value in queue
	if(theFIFO->head == theFIFO->tail) {
        value = theFIFO->head->data;
		theFIFO->head = theFIFO->tail = NULL;
	}
	else if (theFIFO->head != NULL){
        value = theFIFO->head->data;
		theFIFO->head = theFIFO->head->next;
	}
    if (value != NULL) {
        theFIFO->size = theFIFO->size - 1;
    }
    return value;
}

void FIFO_toString(FIFO theFIFO, char *theStr) {
    if (theStr) {
        int i, loops = 0;
        char buf[13];

    // printf("\n\nsize = %d\n\n\n", theFIFO->size);
    // printf("\n\nloops = %d\n\n\n", loops);


    /* Gabe! For some reason I can't think of how to copy the size of the FIFO
       without my new reference "loops", changing as the program goes... this
       is my quick fix until I find out how to actually do it in c, or you
       happen to know. */

    // OPTION 1 - Ideally, this is what I'd like to work...
     loops += theFIFO->size;

    // OPTION 2 - Loop to equivelance
    // while (loops != theFIFO->size) loops += 1;

    // OPTION 3 - Temporarily hard coded.
<<<<<<< HEAD
        loops = 10;
=======
    //loops = 10;

>>>>>>> master


        sprintf(buf, "Q:Count=%d: ", loops); // puts string into buffer
        strcat(theStr,buf);

        for (i = 1; i <= loops; i++) {
            if (i < loops) sprintf(buf, "P%d->", i);
            if (i == loops) sprintf(buf, "P%d-*", i);
            strcat(theStr,buf);
        }
        strcat(theStr," : contents: ");


    	for (i = 0; i < loops; i++) {
    		PCB_p liveData = dequeue(theFIFO); // Pick off the head of the queue
    		enqueue(theFIFO, liveData); // Put it on the back

            // Preparing string for specific node
    		char * pcbString = malloc(50);
    		PCB_toString(liveData, pcbString);

            // Concatenating the node's pcb
    		strcat(theStr,pcbString);
            if (i < loops - 1) strcat(theStr,", ");
    	}
        strcat(theStr,"\n");
    }
}
