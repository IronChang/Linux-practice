#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int a = 0;
int b = 0;
int test()
{
    a++;
    sleep(10);
    b++;
    return a+b;
}
void sigcb(int signo)
{
    printf("signal:%d\n", test());
}
int main()
{
    signal(SIGINT, sigcb);
    printf("main:%d\n", test());
    return 0;
}
