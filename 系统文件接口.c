/*************************************************************************
	> File Name: hello.c
	> Author: TianChang
	> Mail: 408662026@qq.com 
	> Created Time: 2019年10月26日 星期六 13时03分50秒
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>


int main()
{
	//写入文件
	umask(0);//暂时性的修改权限掩码
	int fd = open("myfile",O_WRONLY | O_CREAT,0644);
	if(fd < 0)
	{
		perror("open:");
		return 1;
	}
	int count = 5;
	const char* msg = "hello world!\n";
	int len = strlen(msg);

	while(count--)
	{
		write(fd,msg,len);
	}	
	close(fd);

	//读出文件
	fd = open("myfile",O_RDONLY);
	if(fd < 0)
	{
		perror("open:");
		return 1;
	}
	char buf[1024];
	while(1)
	{
		size_t s = read(fd,buf,len);
		if(s > 0)
		{
			printf("%s",buf);
		}
		else
		{
			break;
		}
	}
	close(fd);
	return 0;
}
