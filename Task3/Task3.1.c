#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
 pid_t pid_main, pid1,pid1a, pid2,pid2a;
 pid_main = fork();
 int count=0;
 if(pid_main==0){
   count++;
   printf("Процесс - потомок\n");
   printf("Child main, adr = %p, count = %d, pid = %d\n",&count,count,getpid());
   pid1 = fork();
   if(pid1 ==0){
       count++;
       printf("Процесс - потомок\n");
       printf("Child 1, adr = %p, count = %d, pid = %d\n",&count,count,getpid());
       pid1a = fork();
       if(pid1a ==0){
         count++;
         printf("Процесс - потомок\n");
         printf("Child 1a, adr = %p, count = %d, pid = %d\n",&count,count,getpid());
       }else if(pid1a > 0){
         count++;
         printf("Child 1a, adr = %p, count = %d, pid = %d\n",&count,count,getpid());
         printf("Родительский процесс pid = %d, pid потомка 1a %d\n",getpid(), pid1a);
      }
   }else if(pid1 > 0){
    count++;
    printf("Child 1, adr = %p, count = %d, pid = %d\n",&count,count,getpid());
    printf("Родительский процесс pid = %d, pid потомка 1 %d\n",getpid(), pid1);
   }
 }else if(pid_main>0){
    count++;
    printf("Child main, adr = %p, count = %d, pid = %d\n",&count,count,getpid());
    printf("Родительский процесс pid = %d, pid потомка main %d\n",getpid(), pid_main);
    pid2 = fork();
    if(pid2==0){
       count++;
       printf("Процесс - потомок\n");
       printf("Child 2, adr = %p, count = %d, pid = %d\n",&count,count,getpid());
       pid2a = fork();
       if(pid2a == 0){
         count++;
         printf("Процесс - потомок\n");
         printf("Child 2a, adr = %p, count = %d, pid = %d\n",&count,count,getpid());
       }else if(pid2a > 0){
         count++;
         printf("Child 2a, adr = %p, count = %d, pid = %d\n",&count,count,getpid());
         printf("Родительский процесс pid = %d, pid потомка 2a %d\n",getpid(), pid2a);
       }
    }else if(pid2>0){
       count++;
       printf("Child 2, adr = %p, count = %d, pid = %d\n",&count,count,getpid());
       printf("Родительский процесс pid = %d, pid потомка 2 %d\n",getpid(), pid2);
    }
 }
 sleep(5);
 return 0;
}