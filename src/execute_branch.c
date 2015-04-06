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

void execute_branch(armsimvariables* var)		 // PC = PC + offset * 4 + 8
{
    var->R[15] -= 4;                             // Incremented from fetch

	uint32_t offset = (var->instruction_word & 0x00FFFFFF); 
	uint8_t sign = ((offset & 0x800000) >> 23);	 // Extract sign

	if (sign == 1)				                 // Sign extension
		offset |= 0xFF000000;
	else
		offset |= 0x00000000;

	offset <<= 2;
	offset += 8;
	var->R[15] += offset;

#ifdef STATUS
        printf("EXECUTE : Branch to 0x%x\n", var->R[15]);
#endif 


}
