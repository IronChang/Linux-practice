#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>


//打印菱形
//int main()
//{
//	int i = 0;
//	scanf("%d", &i);
//	printflingxing(i);
//	system("pause");
//	return 0;
//}
//
//void printline(int blacck_count, int start_count)
//{
//	int i = 0;
//
//	for (i = 0; i < blacck_count; i++)//打印空格
//	{
//		printf(" ");
//	}
//
//	for (i = 0; i < start_count; i++)//打印*号
//	{
//		printf("*");
//	}
//
//	printf("\n");
//}
//
//void printflingxing(int n)
//{
//	int i = 1;
//	for (i = 1; i < n; i++)
//	{
//		printline(n - i, 2 * i - 1);//打印菱形上半部分
//	}
//
//	printline(0, 2 * n - 1);//打印中间一行
//
//	for (i = n - 1; i > 0; i--)//打印菱形下半部分
//	{
//		printline(n - i, 2 * i - 1);
//	}
//}


//查找水仙花数
//int main()
//{
//	int i = 0;
//	for (i; i <= 999; i++)//0—999之间的水仙花数
//	{
//		int a = 0,b = 0, c = 0;
//		int n=0;
//		a = i / 100;//分理处百位
//		b = (i / 10) % 10;//分离出十位
//		c = i % 10;//分理出个位
//		n = a*a*a + b*b*b + c*c*c;
//		if (i == n)//判断是否是水仙花数
//		{
//			printf("%d  ", i);
//		}
//
//	}
//
//	system("pause");
//	return 0;
//}
//
//
//Sn=a+aa+aaa+aaaa+aaaaa的前5项之和
//int main()
//{
//
//	int n = 0, i = 0;
//	scanf("%d", &n);
//	int sum = n;
//  int temp = n;
//
//	for (i = 0; i < 4; i++)
//	{
//		temp= temp * 10 + n; //计算a+aa+aaa+aaaa+aaaaa
//		sum =sum + temp;
//	}
//	printf("Sn=%d\n", sum);
//
//	system("pause");
//	return 0;
//}