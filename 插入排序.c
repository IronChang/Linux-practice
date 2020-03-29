//选择排序
void SelectSort(int *array, int size)
{
	for (int i = 0; i < size - 1; i++)
	{

		int MaxPos = 0;

		for (int j = 1; j < size-i; j++)
		{
			if (array[j]>array[MaxPos])
			{
				MaxPos = j;
			}
		}
		if (MaxPos != size - i - 1)
		{
			Swap(&array[MaxPos], &array[size - 1 - i]);
		}
	}
}

void SelectSortOP(int *array, int size)
{
	int begin = 0;
	int end = size - 1;
	while (begin<=end)
	{
		int Maxpos = begin;//标记最大数
		int Minpos = begin;//标记最小数
		
		for (int i = begin; i <= end; i++)
		{
			if (array[i] > array[Maxpos])
				Maxpos = i;
			if (array[i] < array[Minpos])
				Minpos = i;
		}
		
		Swap(&array[begin], &array[Minpos]);
		//if (Maxpos == begin)
		//{
		//	Maxpos = Minpos;
		//}
		Swap(&array[end], &array[Maxpos]);

		begin++;
		end--;
	}

}