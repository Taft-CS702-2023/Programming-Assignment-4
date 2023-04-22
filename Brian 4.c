#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid; 
    int status; 
    printf("Parent process PID: %d\n", getpid()); // PID of parent process
    pid = fork(); 
    if (pid == 0) 
    { // child process
        printf("Child process PID: %d\n", getpid()); //  PID of child process
        exit(0); // terminate the child process
    } else if (pid > 0) 
    { // parent process
        wait(&status); // wait for child process 
        printf("Child process exited with status: %d\n", WEXITSTATUS(status)); // display exit status of child process
    } else 
    { // error
        perror("fork failed");
        exit(1);
    }
    char filename[100], pattern[100], command[200];
    printf("Enter filename: ");
    scanf("%s", filename);
    printf("Enter pattern to search: ");
    scanf("%s", pattern);
    sprintf(command, "grep %s %s", pattern, filename); // construct the command to run grep
    system(command); // run grep using the system() function
    return 0;
}
