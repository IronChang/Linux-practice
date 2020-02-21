/*************************************************************************
	> File Name: procmask.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2019年10月31日 星期四 20时43分29秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>


void sigcb(int signum)
{
	printf("recv signal:%d\n",signum);
}

int main()
{
	signal(SIGINT,sigcb);
	signal(40,sigcb);

	sigset_t mask_set,old_set;//设置信号集合
	sigemptyset(&mask_set);//清空信号集合
	sigfillset(&mask_set);//添加所有信号到集合中
	sigprocmask(SIG_BLOCK,&mask_set,&old_set);//阻塞mask_set中所有信号
	printf("press enter to continue!\n");
	getchar();//不按回车，则流程就卡在这里

	sigprocmask(SIG_UNBLOCK,&mask_set,NULL);//解除阻塞
	//sigprocmask(SIG_SETMASK,&old_set,NULL);//解除阻塞
	return 0;
}
