#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
  pid_t pid = fork();
  if(pid < 0)
  {
    perror("fork error");
    return -1;
  }

  if(pid == 0)//child process
  {
    printf("I am child,My pid :%d\n",getpid());
  }
  else//parent
  {
    printf("I am parent,My pid :%d\n",getpid());
  }
  
  return 0;
}
