#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
  pid_t pid  = fork();
  if(pid < 0)
  {
    perror("fork error");
    return -1;
  }

  if(pid == 0)
  {
    //child
    printf("I am child:%d\n",getpid());
    //sleep(3);
    exit(123);
  }
  else
  {
    //parent
    printf("I am parent:%d\n",getpid());
    printf("I am parent, Wait child process\n");
    int status;
    int ret = wait(&status);
    //int ret = waitpid(-1,&status,0);
    if(ret < 0)
    {
      perror("wait error");
      return -1;
    }
    if((status&0x7f)==0)
    {
      printf("exit success:exit status : %d\n",WEXITSTATUS(status));
    }
    else
    {      
      printf("exit faile:exit signal:%d\n",status & 0x7f);
    }

  }


  return 0;
}

