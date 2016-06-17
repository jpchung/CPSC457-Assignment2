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
	http://lxr.cpsc.ucalgary.ca/lxr/#linux+v2.6.32/include/linux/sched.h#L1215
	http://www.ibm.com/developerworks/library/l-kernel-memory-access/
	http://lxr.free-electrons.com/source/include/linux/pid.h
	http://www.makelinux.net/books/lkd2/ch11lev1sec4
	http://stackoverflow.com/questions/11223523/what-is-the-meaning-of-gfp-in-kmalloc-flags
	https://www.kernel.org/doc/htmldocs/kernel-hacking/routines-kmalloc.html
	http://www.makelinux.net/ldd3/chp-11-sect-5
