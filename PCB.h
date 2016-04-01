/*
 * Group 3 OS ADTs
 */

enum state_type {new, ready, running, waiting, halted};

struct process_control_block_tag {
  unsigned long pid;        // process ID #, a unique number
  enum state_type state;    // process state (running, waiting, etc.)
  unsigned short priority;  // priorities 0=highest, 15=lowest
  unsigned long pc;         // holds the current pc value when preempted
};

typedef struct process_control_block_tag * PCB_p;

PCB_p PCB_construct(void); // returns a pcb pointer to heap allocation
void PCB_destruct(PCB_p);  // deallocates pcb from the heap
int PCB_init(PCB_p);       // sets default values for member data
int PCB_set_pid(PCB_p, unsigned long pid);
unsigned long PCB_get_pid(PCB_p);  // returns pid of the process

char * PCB_toString(PCB_p);  // returns a string representing the contents of the pcb

#ifndef ADT
#define ADT
#include "PCB.c"
#endif

