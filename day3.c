void SwapGroup(int a[], int b[], int n)
{
	//	交换两个数组的内容
	for (int i = 0; i < n; i++){
		int temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
	printf("数组a：");

	for (int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}	
	printf("\n");
	printf("数组b：");

	for (int i = 0; i < n; i++){
		printf("%d ", b[i]);
	}
	printf("\n");

}

void Calculation()
{
	//计算1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值
	double sum = 0.0;
	int flag = 1;
	for (int i = 1; i < 101; i++)
	{
		sum +=(flag * 1.0 )/i;
		flag = -flag;
		printf("%lf\n", sum);
	}
	printf("计算结果为:%lf\n", sum);	
}

void Calculation2()
{
	//数一下 1到 100 的所有整数中出现多少次数字9
	int count = 0;
	for (int i = 1; i < 101; i++)
	{
		if (i % 10 == 9){
			printf("%d ", i);
			count++;
		}
		if (i / 10 == 9){
			printf("%d ", i);
			count++;
		}
	}
	printf("\n");
	printf("9出现的次数:%d\n", count);
}