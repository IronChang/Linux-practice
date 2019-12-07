#include<iostream>
#include<string>
#include<stdlib.h>
#include"Udpsocket.hpp"

int main(int argc,char* argv[])
{

  if(argc != 3)
  {
    printf("缺少---ip----port\n");
    return -1;
  }

  //这两个地址信息是服务端的地址信息，表示数据要从客户端发给谁
  string srv_ip = argv[1];
  uint16_t srv_port = atoi(argv[2]);
  udpsocket sock;
  if(sock.Socket() == false)
  {
    return -1;
  }

  //一般客户端的地址信息同行并不需要用户自己自动绑定，因为操作系统会检测，若没有绑定则操作系统会为该客户端选择一个合适的ip地址和端口进行绑定，
  
  while(1)
  {
      cout<<"client say:";
      fflush(stdout);
      string buf;
      cin>>buf;
      sock.Send(buf,srv_ip,srv_port);
      buf.clear();
      sock.Recv(buf);
      cout<<"server say:"<<buf<<endl;
  }

  sock.Close();
  cout<<"hello eorld"<<endl;
  return 0;

}
