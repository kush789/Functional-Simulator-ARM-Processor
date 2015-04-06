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

void decode(armsimvariables* var)
{
    uint8_t temp;
    uint8_t shift;

    temp = (var->instruction_word & 0x0C000000) >> 26;    // 27, 26

    if (temp == 0)
    {
        var->is_dataproc = 1;
#ifdef STATUS
        printf("DECODE : Instruction decoded, type : data processing\n");
#endif        
    }

    else if (temp == 1)
    {
        var->is_datatrans = 1;
#ifdef STATUS
        printf("DECODE : Instruction decoded, type : data transfer\n");
#endif         
    }

    else if (temp == 2)
    {
        var->is_branch = 1;
#ifdef STATUS
        printf("DECODE : Instruction decoded, type : branch\n");
#endif         
    }

    else if (temp == 3)
    {
        var->swi_exit = 1;
#ifdef STATUS
        printf("DECODE : Instruction decoded, SWI_EXIT\n");
#endif         
    }

    if (var->is_dataproc)
        decode_dataproc(var);

    if (var->is_datatrans)
        decode_datatrans(var);

    if (var->is_branch)
        decode_branch(var);
}