#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>

int main(int argc,char* argv[])
{
  if(argc!=3)
  {
    printf("缺少---ip----port----error\n");
    return -1;
  }
  //从参数中得到地址和端口信息
  uint16_t port = atoi(argv[2]);
  char* ip = argv[1];

  //设置地址结构信息
  struct sockaddr_in addr;
  addr.sin_family=AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = inet_addr(ip);
  //in_addr_t inet_addr(cosnt char*ip);讲一个点分十进制的IP地址转换为网络字节序的IP地址;
  socklen_t len = sizeof(struct sockaddr_in);

  //第一步创建套接字
  int sockfd = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);//创建一个ipv4类型且使用流式传输的字节流套接字
  if(sockfd < 0)
  {
    perror("create socket error");
    return -1;
  }

  //第二步为套接字绑定地址信息
  int ret = bind(sockfd,(struct sockaddr*)&addr,len);
  if(ret < 0)
  {
    perror("bind socket error");
    return -1;
  }

  //第三步作为服务端，可定是被动接受请求的一端，先接受数据
  while(1)
  {
    char buf[1024] = {0};
    struct sockaddr_in cliaddr;
    ret = recvfrom(sockfd,buf,1023,0,(struct sockaddr*)&cliaddr,&len);//len在这里是一个输入输出型参数，表示想要接收到对端地址的长度以及实际接收到的对端地址长度;
    if(ret < 0)
    {
      perror("recv error");
      return -1;
    }
    printf("client say:%s\n",buf);
    printf("server say:");
    fflush(stdout);
    memset(buf,0x00,1024);
    scanf("%s",buf);
    //第四部及时收到客户端发送的数据时，回复客户端发送是数据
    ret = sendto(sockfd,buf,strlen(buf),0,(struct sockaddr*)&cliaddr,len);
    if(ret < 0)
    {
      perror("send error");
      return -1;
    }
  }
  //第五步关闭套接字
  close(sockfd);
  return 0;
}
