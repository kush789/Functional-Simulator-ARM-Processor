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

void decode_branch(armsimvariables* var)
{
	var->condition = (var->instruction_word & 0xF0000000) >> 28;  // 31, 30, 29, 28

	if (var->condition == 0 && var->Z)			// BEQ, zero flag is true
		var->branch_true = 1;

	else if (var->condition == 1 && !(var->Z))	// BNE, zero flag is false
		var->branch_true = 1;

	else if (var->condition == 10 && !(var->N))	// BGE, not negative
		var->branch_true = 1;

	else if (var->condition == 11 && var->N)	// BLT, negative flag is true
		var->branch_true = 1;

	else if (var->condition == 12 && !(var->N) && !(var->Z))	// BGT, not negative, not zero
		var->branch_true = 1;

	else if (var->condition == 13 && (var->N || var->Z))		// BLE, either negative or zero
		var->branch_true = 1;

	else if (var->condition == 14 )				// Always
		var->branch_true = 1;

	else
		var->branch_true = 0;
}
