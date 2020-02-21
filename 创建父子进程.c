//*************************************************************************
//	> File Name: main.c
//	> Author: TianChang
//	> Mail: 408662026@qq.com
//	> Created Time: 2019年10月14日 星期一 13时58分43秒
//*************************************************************************
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int val = 0;
int main()
{
	pid_t id = fork();
	if(id < 0)
	{
		perror("fork");
		return 0;
	}
	else if(id == 0)
	{
		//child
		printf("child[%d]:%d:%p\n",getpid(),val,&val);
	}
	else
	{
		//parent
		printf("paren[%d]:%d:%p\n",getpid(),val,&val);
	}
	sleep(3);
	return 0;
}
