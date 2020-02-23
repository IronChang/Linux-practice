void reverse_array(int arr[],int len)
{
	for (int i = 0; i < len / 2; i++)
	{
		int temp = arr[i];
		arr[i] = arr[len - 1 - i];
		arr[len - 1 - i] = temp;
	}

	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void Is_Prime(int n)
{
	//素数判断：除了能被自身和1正除外，其他都不能整除的数就是素数
	for (int i = 2; i < n ; i++)
	{
		if (i%n == 0){
			printf("%d 不是素数\n", n);
		}
	}
	printf("%d 是素数\n", n);

}

void Fibonacci1(n)
{
	//非递归斐波那契数列
	//1 1 2 3 5 8
	if (n <= 2)
	{
		printf("%d\n", 1);
	}
	else
	{
		int a = 1;
		int b = 1;
		int c = 0;
		for (int i = 3; i <= n; i++)
		{
			c = a + b;
			a = b;
			b = c;
		}
		printf("%d\n", c);
	}
}

int Fibonacci2(n)
{
	//递归斐波那契数列
	//1 1 2 3 5 8
	if (n == 1 || n == 2)//递归终止条件
		return 1;

	return Fibonacci2(n - 1) + Fibonacci2(n - 2);
}

int N_power(int n,int k)
{
	//编写一个函数实现n^k，使用递归实现
	if (k == 0)
		return 1;

	return n * N_power(n, k-1);
}

int DigitSum(int n)
{
	//输入一个非负整数，返回组成它的数字之和
	if (n < 0)
	{
		printf("输入错误!!!\n");
		return -1;
	}

	if (n / 10 == 0)//表示已经取到最低位
		return n;

	return n % 10 + DigitSum(n / 10);
}

void reverse_string(char* string)
{
	if (*string == '\0')
		return 0;
	reverse_string(string + 1);
	printf("%c ", *string);
}

void jiecheng(int n)
{
	//非递归实现n的阶乘
	int sum = 1;
	int k = n;
	while (n)
	{
		sum = sum*n;
		n--;
	}
	printf("!%d=%d\n", k, sum);
}

int Recursive_jiecheng(int n)
{
	//递归实现n的阶乘
	if (n == 1)
		return 1;

	return n * Recursive_jiecheng(n - 1);
}

int Print_Digit(int n)
{
	//递归方式实现打印一个整数的每一位
	if (n > 9)
		Print_Digit(n / 10);
	printf("%d ", n % 10);

}

size_t strlen(const char* string)
{
	//非递归模拟实现strlen
	//方法一：计数器模式
	//char* p = string;
	//size_t len = 0;

	//while (*p)
	//{
	//	len++;
	//	p++;
	//}
	//printf("长度为:%d\n", len);


	//方法二 利用指针
	char* p = string;
	while (*p)
	{
		p++;
	}
	printf("长度为:%d\n", p - string);
	
}

size_t  Recursive_strlen(const char* string)
{
	//递归实现strlen（）
	if (*string == '\0')
		return 0;

	return 1 + Recursive_strlen(string + 1);
}