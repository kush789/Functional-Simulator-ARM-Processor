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

void decode_type(armsimvariables* var)
{
    uint8_t temp;
    uint8_t shift;

    var->condition = (var->instruction_word & 0xF0000000) >> 28;  // 31, 30, 29, 28
    temp = (var->instruction_word & 0x0C000000) >> 26;    // 27, 26

    if (temp == 0)
        var->is_dataproc = 1;

    else if (temp == 2)
        var->is_branch = 1;


    if (var->is_dataproc)
        decode_dataproc(var);
}