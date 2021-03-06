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

//writes the results back to register file
void write_back(armsimvariables* var)
{
    if (var->is_dataproc)
    {
        if (!(var->store_true || var->load_true))
        {
            var->R[var->register_dest] = var->answer;
#ifdef STATUS
        printf("WRITEBACK : WRITE %zu TO R%zu\n", var->answer, var->register_dest);
#endif        
        }
        else
        {
#ifdef STATUS
        printf("WRITEBACK : NOTHING TO WRITE BACK\n");
#endif    
        }
    }
#ifdef STATUS
    printf("\n\n\n");
#endif
    var->is_datatrans = 0;
    var->is_dataproc = 0;
    var->is_branch = 0;
    var->swi_exit = 0;

    var->load_true = 0;
    var->store_true = 0;
    var->branch_true = 0;
}

