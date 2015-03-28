/*=============================================================================

    This file is part of the Functional Simulator for ARM Processor. It was 
    developed as a part of Computer Architecture Course CS112 offered at 
    IIIT Delhi. 

    This is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    It is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

=============================================================================*/
/******************************************************************************

    Copyright (C) 2015 Kushagra Singh ; kushagra14056@iiitd.ac.in
    Copyright (C) 2015 Lohitaksh Parmar ; lohitaksh14059@iiitd.ac.in

******************************************************************************/

/* 
    myARMSim.h
    Purpose of this file: Implementation file for myARMSim
*/

#include "../include/myARMSim.h"
#include <stdlib.h>
#include <stdio.h>

//Register file

static unsigned long int R[16];

//flags

static int N,C,V,Z;

//memory

static unsigned char MEM_HEAP[4000];    // heap (dynamic allocation)
static unsigned char MEM_STAK[4000];    // stack
static unsigned char MEM_INST[4000];    // instruction memory

//intermediate datapath and control path signals

static unsigned long int instruction_word;
static unsigned long int operand1;
static unsigned long int operand2;


void run_armsim() {
  while(1) {
    fetch();
    decode();
    execute();
    mem();
    write_back();
  }
}

// it is used to set the reset values
// reset all registers and memory content to 0

void reset_proc() 
{
    int i;

    for (i = 0; i < 16; i++)        //Resting registers
        R[i] = 0;

    for (i = 0; i < 4000; i++)      //Reseting instruction memory
        MEM_INST[i] = 0;

    for (i = 0; i < 4000; i++)      //Reseting stack memory
        MEM_STAK[i] = 0;

    for (i = 0; i < 4000; i++)      //Reseting heap memory
        MEM_HEAP[i] = 0;
}

// load_program_memory reads the input memory, and pupulates the instruction memory

void load_program_memory(char *file_name) {
  FILE *fp;
  unsigned long int address, instruction;
  fp = fopen(file_name, "r");
  if(fp == NULL) {
    printf("Error opening input mem file\n");
    exit(1);
  }

  while(fscanf(fp, "%x %x", &address, &instruction) != EOF) {
    write_word(MEM_INST, address, instruction);
  }

  fclose(fp);
}

//writes the data memory in "data_out.mem" file

void write_data_memory() {
  FILE *fp;
  unsigned long int i;
  fp = fopen("data_out.mem", "w");
  if(fp == NULL) {
    printf("Error opening dataout.mem file for writing\n");
    return;
  }
  
  for(i=0; i < 4000; i = i+4){
    fprintf(fp, "%x %x\n", i, read_word(MEM_HEAP, i));
  }
  fclose(fp);
}

//should be called when instruction is swi_exit

void swi_exit() {
  write_data_memory();
  exit(0);
}


//reads from the instruction memory and updates the instruction register
void fetch() {
}
//reads the instruction register, reads operand1, operand2 fromo register file, decides the operation to be performed in execute stage
void decode() {
}
//executes the ALU operation based on ALUop
void execute() {
}
//perform the memory operation
void mem() {
}
//writes the results back to register file
void write_back() {
}


int read_word(char *mem, unsigned long int address) {
  int *data;
  data =  (int*) (mem + address);
  return *data;
}

void write_word(char *mem, unsigned long int address, unsigned long int data) {
  int *data_p;
  data_p = (int*) (mem + address);
  *data_p = data;
}
