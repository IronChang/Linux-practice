#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{

  pid_t pid = fork();
  if(pid < 0)
  {
    perror("create error");
    return -1;
  }

  if(pid == 0)
  {
      //child
      printf("i am child:%d.......\n ",getpid());
      sleep(5);
      exit(112);
      
  }
  else
  {
      //parent
      printf("i am parent:%d.........\n",getpid());

      
     // wait(NULL);
      int ret;
      
      while(1)
      {
      int status = waitpid(pid,&ret,WNOHANG); //阻塞等待任意子进程，并且不关心进程退出状态
      sleep(7);
      if(status < 0)
      {
        printf("wait error------>%d\n",status);
        break;
      }
      else if(status > 0)
      {
      printf("wait success-------%d\n",ret);
      printf("success exit-----exit status:%d\n",(ret>>8)&0xff);
      printf("faile exit-----exit signal:%d",ret&0x7f); 
      break;
      }  
      else
      {
        sleep(1);//相当于等待的进程未退出，但是着这个间隙父进程可以去做别的事情，然后回过头来再次等待；
        
        printf("father wait again---休息一下，父进程去吃个面，吃完再等一次\n");
        
      }
      }   
  }

  return 0;
}
