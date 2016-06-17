CPSC 457 Assignment 2 - README Johnny Phuong Chung

DESCRIPTION:
- The purpose of the ptag user level program is to add or remove a tag from a process using its process ID. This will achieved within the program via a request to the kernel for a system call of the same name, which we have defined.

COMPILE/RUN: 
- Apply the patch linux-2.6.32.A2.patch to corresponding PRISTINE linux kernel (linux-2.6.32.22)
- Use Makefile to compile and link the ptag program
- use command $./ptag to run program

USAGE: $./gls pid -mode tag
- pid = process ID
- mode: 'a' to add tag
- mode: 'r' to remove tag
- tag: desired tag to add or remove 

ASSUMPTIONS/COMMENTS:
- system call and user program can add and remove single tag for an active process
- linked list implementation was attempted, but often resulted in kernel panic due to improper memory allocation/deallocation in kernel
- nested structures for tag and tag list were originally implemented, but pointer management proved difficult and hindered kernel compilation
- forking ,tagstat and tagkill utitilities were not implemented due to time constraints
- system call compiles, but warnings are still present

SOURCES:
