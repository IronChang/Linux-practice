#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);

	for (int i = 0; i<s2.size(); i++)
	{
		for (int j = 0; j < s1.size(); j++)
		{
			if (s1[j] == s2[i])
			{
				s1.erase(s1.begin() + j);
			}
		}
	}
	cout << s1 << endl;
	system("pause");
	return 0;
}