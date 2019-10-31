/*************************************************************************
	> File Name: niming.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2019年10月31日 星期四 10时43分34秒
 ************************************************************************/

#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main()
{
	int pipefd[2]={0};
	int ret = pipe(pipefd);//创建管道
	if( ret < 0)
	{
		perror("pipe error");
		return -1;
	}

	int pid1 = fork();
	if(pid1<0)
	{
		perror("fork() error");
		return -1;
	}
	else if(pid1 == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1],1);
		execlp("ps","ps","-ef",NULL);
		exit(0);
	}

	int pid2 = fork();
	if(pid2 < 0)
	{
		perror("fork() error");
		return -1;
	}
	else if(pid2 == 0)
	{
		close(pipefd[1]);
		dup2(pipefd[0],0);
		execlp("grep","grep","ssh",NULL);
		exit(0);
	}
	close(pipefd[1]);
	close(pipefd[0]);
	waitpid(pid1,NULL,0);
	waitpid(pid2,NULL,0);
	return 0;
}




/*************************************************************************
	> File Name: mingming.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2019年10月31日 星期四 11时10分09秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>

int main()
{
	char *file = "./ppp.fifo";
	int ret = mkfifo(file,0664);
	if(ret < 0 )
	{
		if(errno != EEXIST)
		{
		perror("mkfifo error");
		return -1;
		}
	}

	int fd = open(file,O_RDONLY);
	if(fd < 0)
	{
		perror("open error");
		return -1;
	}
	printf("open sucess!\n");
	
	while(1)
	{
		char buf[1024]={0};
		int ret = read(fd,buf,1023);
		if(ret == 0)
		{
			printf("管道没有人写入");
			return 0;
		}
		else if(ret < 0)
		{
			perror("read error");
			return -1;
		}
		printf("buf:[%s]\n",buf);
	}
	return 0;
}

