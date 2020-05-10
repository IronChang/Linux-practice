#include<unistd.h>
#include<iostream>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string>
#include<stdio.h>

//自己动手封装UdpSocket类，方边使用

class udpsocket
{
  public:
    udpsocket()
    {}

    //1、创建套接字
    bool Socket()
    {
      _sockfd = socket(AF_INET,SOCK_DGRAM,0);
      if(_sockfd < 0)
      {
        std::cerr<<"create error\n";
        return false;
      }
      return true;
    }

    //2、为套接字绑定地址信息
    bool Bind(const std::string &ip,const uint16_t port)
    {
      struct sockaddr_in addr;
      addr.sin_family = AF_INET;
      addr.sin_port = htons(port);
      addr.sin_addr.s_addr = inet_addr(ip.c_str());
      socklen_t len  = sizeof(struct sockaddr_in);
      int ret = bind(_sockfd,(struct sockaddr*)&addr,len);
      if(ret < 0)
      {
        std::cerr<<"bind error\n";
        return false;
      }
      return true;
    }

    //3、接收数据
    bool Recv(std::string &buf,std::string* ip = NULL,uint16_t* port = NULL)
    {
      //接收数据，顺便记录数据是谁发送过来的,以便于会数据的时候知道往什么地方会
      struct sockaddr_in addr;
      socklen_t len = sizeof(struct sockaddr_in);
      char tmp[4096] = {0};
      int ret = recvfrom(_sockfd,tmp,4095,0,(struct sockaddr*)&addr,&len);
      if(ret < 0)
      {
        std::cerr<<"recv error\n";
        return false;
      }

      buf.assign(tmp,ret);//函数的作用就是将数组tmp中的ret长度的字符拷贝buf中
      if( ip != NULL )
      {
        *ip = inet_ntoa(addr.sin_addr);
      }
      if(port != NULL)
      {
        *port = ntohs(addr.sin_port);
      }
      return true;
    }

    //4、发送数据
    bool Send(const std::string& buf,std::string& dip,uint16_t dport)
    {
      struct sockaddr_in addr;
      addr.sin_family = AF_INET;
      addr.sin_port = htons(dport);
      addr.sin_addr.s_addr=inet_addr(dip.c_str());
      socklen_t len = sizeof(struct sockaddr_in);
      int ret = sendto(_sockfd,&buf[0],buf.size(),0,(struct sockaddr*)&addr,len);
      if(ret < 0)
      {
        std::cerr<<"send error\n";
        return false;
      }
      return true;

    }
    
    //5、关闭套接字
    bool Close()
    {
      close(_sockfd);
      return true;
    }
  private:
    int _sockfd = -1;
};

