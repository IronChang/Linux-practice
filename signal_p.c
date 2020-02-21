/*************************************************************************
	> File Name: signal_p.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2019年10月31日 星期四 19时07分03秒
 ************************************************************************/

#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>

struct sigaction oldact;

void sidcd(int signum)
{
	printf("recv a signal:%d\n",signum);
	sigaction(signum,&oldact,NULL);
}

int main()
{
	//signal(2,sidcd);
	//signal(3,sidcd);
	struct sigaction newact;
	newact.sa_handler = sidcd;//设置自定义回调函数
	newact.sa_flags = 0;//为0时默认使用sa_handler回调函数
    sigemptyset(&newact.sa_mask);//临时要阻塞的信号集合,进行清空

	sigaction(2,&newact,&oldact);
	while(1)
	{
		printf("=====================\n");
		sleep(3);
	}
	return 0;
}
