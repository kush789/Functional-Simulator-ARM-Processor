# Functional-Simulator-ARM-Processor
This is a Functional Simulator for ARM Processor. It was developed as a part of Computer Architecture Course CS112 offered at IIIT Delhi. Please see documentation for a detailed explaination of the instruction set supported.

## Authors
- Kushagra Singh - kushagra14056@iiitd.ac.in
- Lohitaksh Parmar - lohitaksh14059@iiitd.ac.in

# Installation
- cd to the root directory of project
- sudo make
- sudo make install
- sudo make check

# Execution
Follow sample.c in ./test for an example.
- gcc -o arm sample.c -lARMSim    (link with lib ARMSim)
- ./arm ./sample.mem    (Provide mem file as argument)
