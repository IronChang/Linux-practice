oid Print()
{
	//输出图案
	//打印上半段
	int n = 1;
	for (int i = 0; i < 7; i++){
		for (int j = 0; j < n; j++){
			printf("*");
		}
		printf("\n");
		n += 2;
	}
	n -= 4;
	//打印下半段
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < n; j++){
			printf("*");
		}
		printf("\n");
		n -= 2;
	}
}

void Narcissisti_number()
{
	//计算0-999之间的水仙花数
	//水仙花数：是指一N位数，其各个数之N次方和等于该数
	for (int i = 0; i < 1000; i++)
	{
		if (i / 10 == 0){
			//一位数
			if (i == pow(i, 1)){
				printf("%d ", i);
			}
		}
		else if ((i / 10)<10 && (i / 10)>=1){
			//两位数
			int a = i % 10;
			int b = i / 10;
			if (i == (a*a+b*b)){
				printf("%d ", i);
			}	
		}
		else if (i / 10 >= 10){
			//三位数
			int a = i % 10;
			int b = (i / 10) % 10;
			int c = i / 100;
			if (i == (a*a*a + b*b*b + c*c*c)){
				printf("%d ", i);
			}
		}
	}
	printf("\n");
}

void Sum()
{
	//求Sn = a + aa + aaa + aaaa + aaaaa的前5项之和，其中a是一个数字
	int a = 0;
	printf("请输入一个数字:");
	scanf("%d", &a);

	int sum = 0;//总数
	int k = a;
	for (int i = 0; i < 5; i++)
	{
		sum += a;
		a = a * 10 + k;
	}
	printf("总数等于:%d\n", sum);
}

void BinarySeach(int arr[],int len,int x)
{
	//实现二分查找,通过数组下标
	int begin = 0;
	int end = len - 1;
	
	while (begin <= end)
	{
		int mid = (begin + end) >> 1;//防止溢出
		if (x == arr[mid]){
			printf("找到了下标为:%d\n", mid);
			break;
		}
		else if(x>arr[mid]){
			begin = mid + 1;
		}
		else{
			end = mid - 1;
		}
	}

}

void Conversion()
{
	//大小写字母转换
	char c ;
	printf("请输入:");

	while (1){
		scanf("%c", &c);

		if (c >= 65 && c <= 90){
			//大写转小写
			printf("转换：%c\n", c + 32);
		}
		else if (c >= 97 && c <= 122){
			//小写转大写
			printf("转换：%c\n", c - 32);

		}
	}
}

void PrintTable2()
{
	//输出一个12*12的乘法口诀表
	for (int i = 1; i <= 12; i++)//控制一行
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%2d*%2d=%2d ", i, j, i*j);
		}
		printf("\n");
	}
}

void Swap3(int *a,int *b)
{
	//使用函数实现两个数的交换
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Is_year2(int year)
{
	//实现一个函数判断year是不是润年
	//能被4整除同时不能被100整除的数，或者是能被400整除

	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
	{
		printf("%d是闰年\n", year);
	}
	else
	{
		printf("%d不是闰年\n", year);
	}
}