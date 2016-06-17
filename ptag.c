#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <signal.h>

/*import system call*/
#define __NR_ptag 337

int main(int argc, char *argv[]) {

	/*instance variables*/
	int pidFlag, optFlag;
	char mode;
	long pid;


	/*convert command line input to long pid*/
	pid = strtol(argv[1], NULL, 10);

	/*once converted, check if process exists*/
	pidFlag = kill(pid, 0);
	if(pidFlag == -1) {
		printf("Process does not exist\n");
		exit(1);
	}

	/*check option characters for command line args to define mode*/
	optFlag = getopt(argc, argv,"a:r:");
	
	if(optFlag == 'a'){
		mode = 'a';
		printf("Mode: add tag\n");
	}
	else if(optFlag == 'r'){
		mode  = 'r';
		printf("Mode: remove tag\n");
	}
	else {
		printf("Wrong argument\n");
		exit(1);
	}
	
	/*define tag to add or remove from command line arg*/	
	char *tag = argv[3];

	/*perform system call for ptag in kernel mode*/
	long result = syscall(__NR_ptag, pid, tag, mode);
	
	if(result == 1) {
		printf("Tag addition unsuccessful\n");
		return 1;
	}
	else if (result == 2) {
		printf("Tag removal unsuccesful\n");
		return 2;
	}
	else if (result == 3) {
		printf("Undefined tag type\n");
		return 3;
	}
	else {
		return 0;
	}



}
