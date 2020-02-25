void Swap1(int x, int y)
{
	int temp = x;
	x = y;
	y = temp;
}

void Swap2(int *px, int *py)
{
	int temp = *px;
	*px = *py;
	*py = temp;
}

int main()
{
	int num1 = 1;
	int num2 = 2;
	Swap1(num1, num2);
	printf("Swap1::num1 = %d num2 = %d\n", num1, num2);
	Swap2(&num1, &num2);
	printf("Swap2::num1 = %d num2 = %d\n", num1, num2);
	return 0;
}