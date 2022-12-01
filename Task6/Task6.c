#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>

int main(void){
 system("ps -l");
 printf("###############################################################################\n");
 int status;
 pid_t child_pid;
 child_pid = fork ();
  if (child_pid > 0) {
    sleep (4);
  }
  else {
    exit (0);
  }
  system("ps -l");
   wait(&status);
    if (WIFEXITED (status)) {
   printf ("Code = %d\n", WEXITSTATUS(status));
   }
    printf("###############################################################################\n");
   system("ps -l");
 return 0;
}
