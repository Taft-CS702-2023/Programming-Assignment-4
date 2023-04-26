# Programming-Assignment-4
Implement processes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


int main() {
   pid_t pid; //initialize process id number
   int status;
   char search[100], filename[100], command[200];
   pid = fork();//creates parent and child process by using the fork
   if (pid == 0) {
      
       printf("Child PID: %d\n", getpid());
       printf("Enter the search term: ");
       fgets(search, 100, stdin); //stdin takes input from the user
       search[strcspn(search, "\n")] = '\0'; //strcspn calculates the length of a string before the first occurence of a character
       printf("Enter the file name: ");
       fgets(filename, 100, stdin);// gets user input
       filename[strcspn(filename, "\n")] = '\0';
       sprintf(command, "grep %s %s", search, filename);//stores
       system(command);


       exit(0);//exits child process
   } else if (pid > 0) {
      
       printf("Parent PID: %d\n", getpid());


     
       wait(&status);//performs wait on parent function so that child function can finish


       printf("Child process finished.\n");
   } else {
      
       printf("Fork failed.\n");
       exit(1);
   }


   return 0;
}
