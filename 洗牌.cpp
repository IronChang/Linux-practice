#include<iostream>
#include<vector>
using namespace std;

void  Reform(vector<int> &v)//½øÐÐÏ´ÅÆ
{
	vector<int> n1(v.begin(), v.end());
	int n = v.size() / 2;
	for (int i = 0; i < n; ++i)
	{
		v[2 * i] = n1[i];
		v[2 * i + 1] = n1[i + n];
	}
}

int main()
{
	int T, n, k;
	cin >> T;
	while (T--)
	{
		cin >> n >> k;
		int num = 2 * n;
		vector<int> table(num);
		for (int i = 0; i < num; i++)
		{
			cin >> table[i];
		}
		while (k--)
		{
			Reform(table);
		}

		for (auto& e : table)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	return 0;
}
