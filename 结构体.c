#include <stdio.h>
#pragma pack(8)//设置默认对齐数为8
struct S1
{
	char c1;
	int i;
	char c2;
};
#pragma pack()//取消设置的默认对齐数，还原为默认
#pragma pack(1)//设置默认对齐数为8
struct S2
{
	char c1;
	int i;
	char c2;
};
#pragma pack()//取消设置的默认对齐数，还原为默认

struct A
{
	int _a : 2;
	int _b : 5;
	int _c : 10;
	int _d : 30;
};

int main()
{
	//输出的结果是什么？
	//printf("%d\n", sizeof(struct S1));//输出
	//printf("%d\n", sizeof(struct S2));//输出
	printf("%d\n", sizeof(struct A));//输出
	system("pause");
	return 0;
}