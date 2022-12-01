#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <cstdio>

int main (int argc, char ** argv)
{
  int count1 = 0, count2 = 0;
  pid_t pid; 
  time_t now = time(NULL);
  printf("Пока всего один процесс\n");
  printf("Вызов функции fork...\n");
  pid = fork();
  while(1)
  {
    if (pid == 0) {
      printf("Процесс - потомок\n");
      count1++;
    } else if (pid > 0) {
      printf("Родительский процесс, pid потомка %d\n", pid);
      count2++;
    } else {
      printf("Ошибка вызова fork, потомок не создан\n"); 
    } 
    time_t end = time(NULL);
    if((end - now) == 1)break;
  }
  sleep(1);
  printf("------------------------------------------------------------------------\n");
  if(count2 != 0) printf("Количество выполненого цикла для родительского процесса: %d\n", count2);
  if(count1 != 0) printf("Количество выполненого цикла для дочернего процесса: %d\n", count1);
  return 0;
}

