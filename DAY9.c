#define _CRT_SECURE_NO_WARNINGS 1
//
////计算100-200之间的素数
//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int i, j;
//
//	for (i=100; i<= 200; i++) //进行循环计算查找素数
//	{
//		for (j = 2;j<i; j++)
//		{
//			if (i%j == 0)
//				break;//如果要能整出那就直接跳出该循环
//		}
//		if (j == i)//如果没有整除
//			printf("%d  ", i);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
//
//输出乘法口诀表
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i , j;
	for (i = 1; i <= 9; i++)//控制乘法口诀表的行数
	{
		for (j = 1; j <= i; j++)//控制乘法口诀表的列数
		{
			printf("%d*%d=%2d  ", i, j, i*j);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
//
//

//求出1000-2000之间的闰年
//#include<stdio.h>
//#include<stdlib.h>

//int main()
//{
//	int i;
//  int count = 0;
//	for (i = 1000; i <= 2000; i++)
//	{  
//		if (i % 100 != 0 && i % 4 == 0 || i % 400 == 0)//判断闰年的条件是能被四整除的同时不能被100整除，或者能被400整除。
//		{         
//			printf("%d  ", i);
//          count++;
//		}
//			
//	}
//   printf("闰年数: %d", count);
//	system("pause");
//    return 0;
//}