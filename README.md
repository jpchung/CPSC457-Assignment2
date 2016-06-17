CPSC 457 Assignment 2 - README Johnny Phuong Chung

DESCRIPTION:
- The purpose of the ptag user level program is to add or remove a tag from a process using its process ID. This will achieved within the program via a request to the kernel for a system call of the same name, which we have defined.

COMPILE/RUN: 
- Apply the patch linux-2.6.32.A2.patch to corresponding PRISTINE linux kernel (linux-2.6.32.22)
- Use Makefile to compile and link the ptag program
- use command $./ptag to run program

USAGE:
-$./gls pid -mode tag
	- pid = process ID
	- mode: 'a' to add tag
	- mode: 'r' to remove tag
	- tag: desired tag to add or remove 

ASSUMPTIONS/COMMENTS:

SOURCES:
