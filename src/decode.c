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
    
void shift_op2(armsimvariables* var)        // In case shift is given for operand2
{
    uint8_t shiftbits = ((var->instruction_word & 0x00000FF0) >> 4);
    uint8_t type = shiftbits & 0x01;

    if (!type)  // 00 LSL, 01 LSR, 10 arith right, 11 rot right
    {
        uint8_t what = (shiftbits & 0x06) >> 1;
        uint8_t amount = (shiftbits & 0XF8) >> 3;

        if (what == 0)      // LSL
        {
            var->operand2 <<= amount;
        }
        else if (what == 1) // RSL
        {
            var->operand2 >>= amount;
        }
        else if (what == 2)
        {

        }
        else if (what == 3) // Rot R
        {
            var->operand2 = (var->operand2 >> amount) | (var->operand2 << (64 - amount));
        }
    }
    else if (type)
    {
        uint8_t what = (shiftbits & 0x06) >> 1;
        uint8_t rno = (shiftbits & 0xF0) >> 4;
        uint8_t amount = (var->R[rno] & 0x0000000F);  // bottom byte of R[rno]

        if (what == 0)      // LSL
        {
            var->operand2 <<= amount;
        }
        else if (what == 1) // LSR
        {
            var->operand2 >>= amount;
        }
        else if (what == 2)
        {

        }
        else if (what == 3) // Rot R
        {
            var->operand2 = (var->operand2 >> amount) | (var->operand2 << (64 - amount));
        }        

    }

}

void decode(armsimvariables* var) {

    uint8_t temp;
    uint8_t shift;

    var->condition = (var->instruction_word & 0xF0000000) >> 28;  // 31, 30, 29, 28
    temp = (var->instruction_word & 0x0C000000) >> 26;    // 27, 26

    if (!temp)
        var->is_arth = 1;

    if (var->is_arth)
    {
        var->opcode = (var->instruction_word & 0x1E00000) >> 21;      // 24, 23, 22, 21
        var->immediate = (var->instruction_word & 0x02000000) >> 25;   // 25

        var->register1 = (var->instruction_word & 0x000F0000) >> 16;      // 19, 18, 17, 16
        var->operand1 = var->R[var->register1];
        var->register_dest = (var->instruction_word & 0x0000F000) >> 12;  // 15, 14, 13, 12

        if (var->immediate)         // 11, 10, 9, 8 ->shift; 7 - 0 -> value
        {
            var->operand2 = (var->instruction_word & 0x000000FF);
            shift = (var->instruction_word & 0x00000F00) >> 8;
            var->operand2 <<= shift;
        }
        else if (!var->immediate)   //
        {
            var->register2 = (var->instruction_word & 0x0000000F);
            var->operand2 = var->R[var->register2];
            shift_op2(var);
        }
    }
}