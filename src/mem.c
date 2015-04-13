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

void mem(armsimvariables* var)
{
    if (var->is_datatrans)
    {
        uint8_t immediate = 1 - ((var->instruction_word & 0x02000000) >> 25);
        uint16_t offset;

        if (immediate)
        {
            offset = (var->instruction_word & 0x0FFF);
        }
        else
        {
            var->register2 = (var->instruction_word & 0x0000000F);
            var->operand2 = var->R[var->register2];
            shift_operand2(var);
            offset = var->operand2;
        }

        if (var->store_true)         // STR instruction
        {
            write_word(var->MEM_HEAP, var->R[var->register1] + offset, var->R[var->register_dest]);
#ifdef STATUS
            printf("MEMORY : STORE TO ADDRESS 0x%x VALUE 0x%x\n", var->R[var->register1] + offset, var->R[var->register_dest]);
#endif            
        }

        else if (var->load_true)     // LDR instruction
        {
            var->R[var->register_dest] = read_word(var->MEM_HEAP, var->R[var->register1] + offset);
#ifdef STATUS
            printf("MEMORY : LOAD TO REGISTER R%zu VALUE 0x%x FROM MEM 0x%x\n", var->register_dest, var->R[var->register_dest], var->R[var->register1] + offset);
#endif            
        }        
    }
    else
    {
#ifdef STATUS
        printf("MEMORY : NO MEMORY OPERATION\n");
#endif   
    }
}