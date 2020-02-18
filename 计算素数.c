void FindPrime()
{
	int t = 0;
	for (int n = 100; n <= 200; n++)
	{
		int  i = 0;
		for (i = 2; i < sqrt(n); i++)
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