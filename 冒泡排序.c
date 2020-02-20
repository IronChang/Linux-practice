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