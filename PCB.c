/*
 * Group 3 OS ADTs
 */

#include <stdio.h>

#ifndef ADT
#define ADT
#include "PCB.h"
#endif

PCB_p PCB_construct(void) {
  PCB_p result = malloc(sizeof(PCB_p));

  return result;
}

void PCB_destruct(PCB_P thePCB) {
  if (thePCB) {
    free(thePCB);
  }
}

int PCB_init(PCB_p) {

}

int PCB_set_pid(PCB_p thePCB, unsigned long pid) {
  thePCB->pid = pid;
}

unsigned long PCB_get_pid(PCB_p) {

}

char * PCB_toString(PCB_p thePCB) {

}