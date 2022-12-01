#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <sys/types.h>
#include <string.h>

int main(void){
 pid_t status;
 int exit_status;
 pid_t childpid;
 status = fork();
 if(status==-1){
   fprintf(stderr,"Fork error\n");
   exit(EXIT_FAILURE);
  }
  if(status==0){
   printf("Потомок\n");
   execl("/bin/ps","ps",NULL);
   fprintf(stderr,"Execl error\n");
  }
  childpid = wait(&exit_status);
  if (WIFEXITED(exit_status)) {
  printf ("Process with PID=%d has exited with code=%d\n", childpid, WEXITSTATUS(exit_status));
  }
 if (WIFSIGNALED(exit_status)) {
   printf ("Process with PID=%d has exited with signal \n", childpid);
 }
  return EXIT_SUCCESS;
}