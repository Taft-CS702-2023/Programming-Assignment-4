#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>

int main(){
	pid_t kidpid;
	kidpid = fork(); //creates child process
	if (kidpid < 0){         
		// <0 means error, and >0 means in process
		printf("fork?no.spoon.");
		return 1;
	}
	else if (kidpid == 0){
		printf("child created. kid PID: %d, parent pid: %d", getpid(), getppid()); //getpid vs get!P!pid
		
	} else {
		wait(NULL); //wait for kid process to terminate before moving on
		printf("parent created. kid PID: %d, parent pid: %d", getpid(), getppid());
	}
	return 0;
}

