# /*=============================================================================
#
#     This file is part of the Functional Simulator for ARM Processor. It was 
#     developed as a part of Computer Architecture Course CS112 offered at 
#     IIIT Delhi. 
#
#     This is free software; you can redistribute it and/or modify
#     it under the terms of the GNU General Public License as published by
#     the Free Software Foundation; either version 2 of the License, or
#     (at your option) any later version.
#
#     It is distributed in the hope that it will be useful,
#     but WITHOUT ANY WARRANTY; without even the implied warranty of
#     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#     GNU General Public License for more details.
#
# =============================================================================*/
# /******************************************************************************
#
#     Copyright (C) 2015 Kushagra Singh ; kushagra14056@iiitd.ac.in
#     Copyright (C) 2015 Lohitaksh Parmar ; lohitaksh14059@iiitd.ac.in
#
# ******************************************************************************/
#
# 	 makefile
#    Purpose of this file: Installing the library
#	 Options : check, install, clean

all:
	gcc -o myARMSim.o -c myARMSim.c
	ar -rcs libARMSim.a myARMSim.o
	cp libARMSim.a /usr/local/lib/
	cp libARMSim.a ../lib/
	cp ../include/myARMSim.h /usr/local/include
	rm *.a *.o

install:

check:

clean:
	rm /usr/local/lib/libARMSim.a
	rm /usr/local/include/myARMSim.h
