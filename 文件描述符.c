/*************************************************************************
	> File Name: IO.c
	> Author: TianChang
	> Mail: 408662026@qq.com 
	> Created Time: 2019年10月26日 星期六 14时45分08秒
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main()
{
	int fd = open("mytext",O_RDONLY | O_CREAT,0644);//创建一个文件
	if(fd < 0)
	{
		perror("open:");
		return 1;
	}
	printf("fd:%d\n",fd);//此时fd输出3
	close(fd);
	
	close(0);
	fd = open("mytext",O_RDONLY);
	if(fd < 0)
	{
		perror("open:");
		return 1;
	}
	printf("fd:%d\n",fd);//此时fd输出0
	close(fd);
	return 0;
}

