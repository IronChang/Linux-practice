#include<iostream>
#include<vector>
#include<string>
using namespace std;

--����hashӳ��
int main()
{
	string s;
	while (cin >> s)
	{
		if (s.size() == 0)//��֤�ַ������ǿմ�
		{
			return -1;
		}

		int n[256] = { 0 };
		for (size_t i = 0; i < s.size(); i++)
		{
			n[s[i]]++;
		}
		char pos = 0;
		for (size_t i = 0; i < s.size(); i++)
		{
			if (n[s[i]] == 1)
			{
				pos = s[i];
				cout << pos << endl;
				break;
			}
		}
		if (pos == 0)
		{
			cout << -1 << endl;
		}

	}
	system("pause");
	return 0;
}
