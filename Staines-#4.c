#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
  pid_t pid;
  int status;

  pid = fork(); // Fork a child process
  if (pid < 0) 
  {
    perror("Fork failed"); // Forking failed
    exit(1);
  }  
  else if (pid == 0) // Child process
  {
    printf("Child PID: %d\n", getpid()); // Display Child PID

    // Simulate grep command
    char *grep_args[] = {"grep", "hello", "file.txt", NULL};
    execvp("grep", grep_args);
    perror("Execvp failed");
    exit(1);
  }
  else // Parent process
  {
    // Display Parent PID and Child PID
    printf("Parent PID: %d\n", getpid());
    printf("Child PID: %d\n", pid);

    // Wait for the child process to complete
    wait(&status);

    // Check if the child process terminated normally
    if (WIFEXITED(status))
    {
      printf("Child process terminated normally with exit status: %d\n", WEXITSTATUS(status));
    }
    else
    {
      printf("Child process terminated abnormally\n");
    }
  }
  return 0;
}
