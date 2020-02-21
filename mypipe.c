/*************************************************************************
	> File Name: mypipe.c
	> Author: TianChang
	> Mail: 408662026@qq.com 
	> Created Time: 2019年10月29日 星期二 21时54分49秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main()
{

	int pid = 0;
	int pipefd[2];
	int ret = pipe(pipefd);
	if(ret < 0 )
	{
		perror("make pipe:");
		return -1;
	}

	pid = fork();
	if(pid  < 0)
	{
		perror("fork:");
	}

	if(pid == 0)
	{
		//child ----> write
		
		close(pipefd[0]);//关闭读端，读数据
		const char *str = "i am a good child";
		while(1)
		{
			write(pipefd[1],str,strlen(str));
			sleep(1);
		}
		exit(0);
	}
	else
	{
		//father ----> read
		close(pipefd[1]);//关闭写端只读数据
		char buf[1024];
		while(1)
		{
			ssize_t s = read(pipefd[0],buf,sizeof(buf)-1);
			if(s < 0)
			{
				perror("read:");
				break;
			}
			else
			{
				buf[s] = 0;
				printf("%s\n",buf);
			}
		}
		waitpid(pid,NULL,0);
	}
	
	return 0;
}




/*************************************************************************
	> File Name: pipe.c
	> Author: TianChang
	> Mail: 408662026@qq.com 
	> Created Time: 2019年10月29日 星期二 20时57分29秒
 ************************************************************************/
//这个demo体会匿名管道的基本使用

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int pid = 0;
	int pipefd[2];
	int ret = pipe(pipefd);//创建匿名管道
	if(ret < 0)
	{
		perror("pipe error\n");
		return -1;
	}

	pid = fork();
	if(pid == 0)
	{
		//子进程从管道中读取数据
		close(pipefd[0]);//关闭子进程读端
		//close(pipefd[1]);//关闭子进程的写入段
		sleep(5);
		char buf[1024] = {0};
		int ret = read(pipefd[0],buf,1023);
		if(ret < 0)
		{
			perror("read error\n");
			return -1;
		}
		printf("child get data[%s]\n",buf);
	}
	else
	{
		//父进程向管道中写入数据
		close(pipefd[0]);//关闭子进程的读断
		//close(pipefd[1]);
		sleep(3);
		char *ptr = "今天心情不错！！！";
		(pipefd[1],ptr,strlen(ptr));
		if(ret < 0)
		{
			perror("write error\n");
			return -1;
		}
	}
	return 0;
}

