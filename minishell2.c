//这个demo实现一个简单的bash shell，旨在体会进程控制这一块的相关知识
//bash shell运行流程：
//0、父进程执行等待输入命令
//1、获取输入的命令
//2、解析命令
//3、fork子进程去执行命令
//4、父进程进行wait等待
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>
#include<ctype.h>

int main()
{

  while(1)
  {
  printf("[tc2@localhost ~]$");
  fflush(stdout);
  char buf[1024]={0};
  fgets(buf,1023,stdin);
  buf[strlen(buf)-1]='\0';
  printf("cmd:[%s]\n",buf);

  int argc = 0;//保存命令参数的个数
  char *argv[32]={NULL};
  char *ptr = buf;

  while(*ptr != '\0')//进行命令解析
  {
    if(!isspace(*ptr))//进行注释：isspace()函数是判断一个字符是否是一个空白字符，如果是返回真，如果不是返回假;
    {
        argv[argc]=ptr;
        argc++;
        while(!isspace(*ptr) && *ptr!='\0')
        {
          ptr++;
        }
        *ptr='\0';
    }
    ptr++;
  }

  pid_t pid = fork();//创建子进程开始执行命令
  if(pid ==  0)
  {
    execvp(argv[0],argv);
    exit(1);
  }

     waitpid(-1,NULL,0);//父进程进行等待子进程退出
  }
  return 0;
}
