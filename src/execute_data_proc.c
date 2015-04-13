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

void execute_data_proc(armsimvariables* var)
{
    if (var->opcode == 0)
    {
        var->answer = var->operand1 & var->operand2;
#ifdef STATUS
        printf("EXECUTE : Operation is : AND\n");
        printf("EXECUTE : AND %zu and %zu\n", var->operand1, var->operand2);
#endif        
    }

    else if (var->opcode == 1)
    {
        var->answer = var->operand1 ^ var->operand2;
#ifdef STATUS
        printf("EXECUTE : Operation is : XOR\n");
        printf("EXECUTE : XOR %zu and %zu\n", var->operand1, var->operand2);
#endif        
    }

    else if (var->opcode == 2)
    {
        var->answer = var->operand1 - var->operand2;
#ifdef STATUS
        printf("EXECUTE : Operation is : SUBTRACT\n");
        printf("EXECUTE : SUBTRACT %zu and %zu\n", var->operand1, var->operand2);
#endif        
    }

    else if (var->opcode == 4)
    {
        var->answer = var->operand1 + var->operand2;
#ifdef STATUS
        printf("EXECUTE : Operation is : ADD\n");
        printf("EXECUTE : ADD %zu and %zu\n", var->operand1, var->operand2);
#endif        
    }

    else if (var->opcode == 5)
    {
        var->answer = var->operand1 + var->operand2 + 1;
#ifdef STATUS
        printf("EXECUTE : Operation is : ADD WITH CARRY\n");
        printf("EXECUTE : ADD WITH CARRY %zu and %zu\n", var->operand1, var->operand2);
#endif        
    }

    else if (var->opcode == 10)
    {
        var->answer = var->operand1 - var->operand2;
        update_flags(var);
#ifdef STATUS
        printf("EXECUTE : Operation is : SUBTRACT with SET FLAG\n");
        printf("EXECUTE : SUBTRACT %zu and %zu\n", var->operand1, var->operand2);
#endif  
    }

    else if (var->opcode == 12)
    {
        var->answer = var->operand1 | var->operand2;
#ifdef STATUS
        printf("EXECUTE : Operation is : OR\n");
        printf("EXECUTE : OR %zu and %zu\n", var->operand1, var->operand2);
#endif        
    }

    else if (var->opcode == 13)
    {
        var->answer = var->operand2;
#ifdef STATUS
        printf("EXECUTE : Operation is : MOVE\n");
        printf("EXECUTE : MOVE %zu TO R%zu\n", var->operand1, var->register_dest);
#endif        
    }

    else if (var->opcode == 15)
    {
        var->answer = ~(var->operand2);
#ifdef STATUS
        printf("EXECUTE : Operation is : NOT\n");
        printf("EXECUTE : NOT %zu\n", var->operand2);
#endif        
    }

#ifdef DEBUG
    else
        printf("Opcode wrong in case of execute_data_proc, given is %d\n", var->opcode);
#endif
    
}