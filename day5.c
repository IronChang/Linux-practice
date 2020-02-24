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