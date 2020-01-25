#include<iostream>
using namespace std;

int main()
{
	int n, cur=0, ret = 0;
	cin >> n;
	for (int i = 0; i < 32; i++)
	{
		if ((n & 1) == 1)
		{
			++cur;
			n=(n >> 1);
		}
		else
		{
			if (cur > ret)
			{
				ret = cur;
				//n=(n >> 1);
				cur = 0;
			}
			else
			{
				cur = 0;
				
			}
			n=(n >> 1);
		}
	}
	cout << ret << endl;
	system("pause");
	return 0;
}
