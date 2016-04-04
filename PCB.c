/*
 * Group 3 OS ADTs
 */

#ifndef ADT
#define ADT
#include "PCB.h"
#endif

PCB_p PCB_construct(void) {
  PCB_p *result = malloc(sizeof(PCB));
  return *result;
}

void PCB_destruct(PCB_p thePCB) {
  if (thePCB) {
    free(thePCB);
  }
}

int PCB_init(PCB_p thePCB) {

  //not sure what values to give.

  thePCB->state = new;
  thePCB->priority = 15; // lowest priority?
  thePCB->pid = 0;
  thePCB->pc = 0;
}

int PCB_set_pid(PCB_p thePCB, unsigned long thePID) {
  if (thePID) {
    thePCB->pid = thePID;
  }
}

unsigned long PCB_get_pid(PCB_p thePCB) {
  return thePCB->pid;
}

void PCB_set_state(PCB_p thePCB, state_type theState) {
  if (theState) {
    thePCB->state = theState;
  }
}

state_type PCB_get_state(PCB_p thePCB) {
  return thePCB->state;
}

void PCB_toString(PCB_p thePCB, char *theStr) {
  if (theStr) {
    char state[8];

    if (thePCB->state == new) {
      strcpy(state, "new");
    } else if (thePCB->state == ready) {
      strcpy(state, "ready");
    } else if (thePCB->state == running) {
      strcpy(state, "running");
    } else if (thePCB->state == waiting) {
      strcpy(state, "waiting");
    } else if (thePCB->state == halted) {
      strcpy(state, "halted");
    }

    sprintf(theStr, "PID: %X, State: %s, Priority: %X, PC: %X\n",
      thePCB->pid, thePCB->priority, thePCB->pc);
  }
}