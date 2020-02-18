#include<stdio.h>
#include<stdlib.h>

void FindPrime()
{
	int t = 0;
	for (int n = 100; n <= 200; n++)
	{
		int  i = 0;
		for (i = 2; i <= sqrt(n); i++)
		{
			if (n%i == 0)
			break;
		}
		if (i > (n / 2))
		{
			printf("%d ", n);
			t += 1;
			if (t % 5 == 0)
			printf("\n");
		}
	}
	printf("\n");
}

void PrintTable()
{
	for (int j = 1; j <= 9; j++)//输出一行
	{
		for (int i = 1; i <= j; i++)
		{
			printf("%d*%d=%2d ", j, i, i*j);
		}
		printf("\n");
	}
}

void Is_year()
{
	int t = 0;

	//输出1000年-2000年之间的闰年
	for (int i = 1000; i <= 2000; i++)
	{
		//判断闰年的条件
		if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
		{
			printf("%d ", i);

			t++;
			if (t % 10 == 0)
			{
				printf("\n");
			}
		}
	}
}

void Swap1(int *a, int *b)
{
	//交换两个数
	printf("a:%d,b:%d\n", *a, *b);
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("a:%d,b:%d\n", *a, *b);
}

void Swap2(int *a, int *b)
{
	//不出创建中间变量交换两个数
	printf("a:%d,b:%d\n", *a, *b);
	*a += *b;
	*b = *a - *b;
	*a = *a - *b;;
	printf("a:%d,b:%d\n", *a, *b);
}

void FindMax()
{
	//求10个整数中最大值
	int a[] = { 78, 4, 5, 6, 3, 4, 9, 8, 52, 10 };
	int i = 10;
	int max = 0;
	while (i--)
	{
		if (a[i] > max){
			max = a[i];
		}
	}
	printf("Max:%d\n", max);
	
}

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void BubbleSort()
{
	int a[] = { 3,5,9 };
	int end = 2;
	//全局
	while (end > 0)
	{
		//单趟
		for (int i = 1; i <= end; ++i)
		{
			if (a[i - 1] > a[i])
			{
				swap(&a[i - 1], &a[i]);
			}
		}
		--end;
	}

	for (int i = 0; i < 3; i++)
	{
		printf("%d ", a[i]);
	}
}

void Greatest_divisor1()
{
	//穷举法
	int a = 20, b = 60;
	int min = 0;
	if (a<b)
		min = a;
	else
		min = b;

	for (int i = min; i>0; i--)
	{
		if ((a%i) == 0 && (b%i) == 0)
		{
			printf("最大公约数为：%d\n", i);
			break;
		}
	}
}

void Greatest_divisor2()
{
	//相减法
	int a = 16;
	int b = 6;
	while ((a - b) != 0)//两个数相等时，最大公约数为他们其中任意一个。
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}

	printf("最大公约数为：%d\n", b);
}


int main()
{
	//FindPrime();
	//PrintTable();
	//Is_year();
	//int a = 4, b = 7;
	//Swap2(&a, &b);
	//FindMax();
	//BubbleSort();
	Greatest_divisor2();
	system("pause");
	return 0;
}