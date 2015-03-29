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

#include <stdint.h>

#define DEBUG 1         // Comment to switch off debug

// Mmemory, flags, registers for ARMSim
typedef struct _armsimvar{
    
    //Register file, r15 -> PC
    int32_t R[16];

    //flags
    uint8_t N, Z;

    //memory
    int8_t MEM_HEAP[4000];      // heap (dynamic allocation)
    uint8_t MEM_INST[4000];     // instruction memory

    // intermediate datapath and control path signals
    uint32_t instruction_word;
    int32_t operand1;
    int32_t operand2;
    int32_t answer;
    uint8_t register1;
    uint8_t register2;
    uint8_t register_dest;

    uint8_t branch_true;        // In case branch condition is met
    uint8_t store_true;         // In case intruction is load
    uint8_t load_true;          // In case instruction is store

    // required for decoding
    uint8_t condition;
    uint8_t is_dataproc;
    uint8_t is_branch;
    uint8_t is_datatrans;
    uint8_t opcode;
    uint8_t immediate;

} armsimvariables;

/* Support Functions */

// Initiates variables to 0;
void init_memory(armsimvariables* var);

// Initates ARMSim
void run_armsim(armsimvariables* var);

// Used to read instructions from mem file
void load_program_memory(char* file_name, armsimvariables* var);

// Write back data from heap to file
void write_data_memory(armsimvariables* var);

// Exit ARMSim
void swi_exit(armsimvariables* var);

//reads from the instruction memory and updates the instruction register
void fetch(armsimvariables* var);

// decides whether data process or ...
void decode(armsimvariables* var);

// decode in case instruction has data proccessing
void decode_dataproc(armsimvariables* var);

// decode in case instruction has branch
void decode_branch(armsimvariables* var);

// decode in case instruction is of data transfer type
void decode_datatrans(armsimvariables* var);

// Reset variables required for decoding
void reset_decode_variables(armsimvariables* var);

// In case operand two requires shifting
void shift_operand2(armsimvariables* var);        

//executes the ALU operation based on ALUop
void execute(armsimvariables* var);

// executes in case data processing instruction
void execute_data_proc(armsimvariables* var);

// executes in case data processing instruction
void execute_data_trans(armsimvariables* var);

// executes in case of branch instruction
void execute_branch(armsimvariables* var);

// Updates N, Z flags in case of CMP
void update_flags(armsimvariables* var);

//perform the memory operation
void mem();

//writes the results back to register file
void write_back();

// reads one word from array mem
uint32_t read_word(char *mem, uint32_t address);

// writes one word to array ponter mem + address
void write_word(char *mem, uint32_t address, uint32_t data);