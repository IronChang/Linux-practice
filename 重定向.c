/*************************************************************************
	> File Name: io.c
	> Author: TianChang
	> Mail: 408662026@qq.com 
	> Created Time: 2019年10月26日 星期六 15时55分49秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

//写入读出
int main()
{
	int fd = open("./log",O_CREAT | O_RDWR,0644);
	if(fd < 0)
	{
		perror("open:");
		return 1;
	}
	close(1);
	dup2(fd,1);//将1号标识符重定向到fd
	for(;;)
	{
		char buf[1024]={0};
		ssize_t s = read(0,buf,1023);
		if(s < 0)
		{
			perror("read:");
			break;
		}
	printf("%s\n",buf);
	fflush(stdout);
	}

	return 0;
}
