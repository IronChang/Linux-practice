#include<iostream>
#include<stdlib.h>
using namespace std;


void ShuGen(string s)
{
	int ret = 0;
	while (s.size() != 1)
	{
		ret = 0;
		for (int i = s.size() - 1; i >= 0; i--)
		{
			ret += (s[i] - '0');
		}
		s.clear();
		char buf[10000];
		_itoa(ret, buf, 10);
		s+=(buf);
	}
	cout << s << endl;
}

int main()
{
	string s;
	int num = 0;
	while (cin >> s)
	{
		ShuGen(s);
	}
	system("pause");
	return 0;
}
