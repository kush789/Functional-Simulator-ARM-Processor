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

#include <myARMSim.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void init_memory(armsimvariables* var)
{
	int i;

    for (i = 0; i < 16; i++)        //Resting registers
        var->R[i] = 0;

    for (i = 0; i < 4000; i++)      //Reseting instruction memory
        var->MEM_INST[i] = 0;

    for (i = 0; i < 4000; i++)      //Reseting stack memory
        var->MEM_STAK[i] = 0;

    for (i = 0; i < 4000; i++)      //Reseting heap memory
        var->MEM_HEAP[i] = 0;

    var->instruction_word = 0;
    var->operand1 = 0;
    var->operand2 = 0;
    var->answer = 0;
    var->register1 = 0;
    var->register2 = 0;
    var->register_dest = 0;
    var->condition = 0;
    var->is_dataproc = 0;
    var->is_branch = 0;
    var->opcode = 0;
    var->immediate = 0;
}
