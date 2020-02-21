/*
  简单的封装一个socket类来实现，udp编程；
*/

#include <iostream>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string>
#include<unistd.h>
#include<stdio.h>
using namespace std;

class udpsocket
{
  private:
    int _sockfd;
  private:
      //先封装一个地址结构
      void MakeAddr(struct sockaddr_in &addr,const string &ip,const uint16_t port)
      {
        addr.sin_family = AF_INET;
        addr.sin_port=htons(port);
        addr.sin_addr.s_addr = inet_addr(ip.c_str());
      }
    public:
      udpsocket():_sockfd(-1)
      {  }
      //1、创建套接字
      bool Socket()
      {
        _sockfd = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
        if(_sockfd<0)
        {
          perror("create socket error");
          return false;
        }
      return true;
      }  

      //3.为套接字绑定地址信息
      bool Bind(const string &ip,const uint16_t port)
      {
        struct sockaddr_in addr;
        MakeAddr(addr,ip,port);
        socklen_t len = sizeof(struct sockaddr_in);
        int ret = bind(_sockfd,(struct sockaddr*)&addr,len);
        if(ret<0)
        {
          perror("bind error");
          return false;
        }
        return true;
      }
      //4.发送数据
      bool Send(const string &buf,string &dip,uint16_t dport)
      {
        struct sockaddr_in addr;
        MakeAddr(addr,dip,dport);
        socklen_t len = sizeof(struct sockaddr_in);
        int ret = sendto(_sockfd,&buf[0],buf.size(),0,(struct sockaddr*)&addr,len);
        if(ret < 0)
        {
          perror("sendto error");
          return false;
        }
        return true;
      }

      //5.接受数据
      bool Recv(string &buf,string *ip = NULL,uint16_t *port = NULL)
      {
        struct sockaddr_in addr;
        socklen_t len = sizeof(struct sockaddr_in);
        char tmp[4096]={0};

        int ret = recvfrom(_sockfd,tmp,4095,0,(struct sockaddr*)&addr,&len);
        if(ret < 0)
        {
          perror("recv error");
          return false;
        }

        buf.assign(tmp,ret);
        if(ip != NULL)
        {
          *ip = inet_ntoa(addr.sin_addr);
        }

        if(port != NULL)
        {
          *port = ntohs(addr.sin_port);
        }
        return true;
      }

      //6.关闭套接字
      bool Close()
      {
        close(_sockfd);
          return true;
      }
};
