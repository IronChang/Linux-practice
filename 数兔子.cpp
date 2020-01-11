//属兔子总结规律其实就是：斐波那契数列f(n) = f(n-1)+f(n-2)
#include<iostream>
using namespace std;

int GetTotalCount(int month)
{
	if (month == 1 || month == 2)
		return 1;
	return GetTotalCount(month - 1) + GetTotalCount(month - 2);
}

int main()
{
	int month;
	while (cin >> month)
	{
		cout << GetTotalCount(month) << endl;
	}
	return 0;
}
