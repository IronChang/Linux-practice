
#include<iostream>
#include<vector>
#include<string>
using namespace std;
//int MaxFactor(int x,int y)//�������Լ����������С������
//{
//	int i = 1, max = 1;
//	while (i <= x&&i <= y)
//	{
//		if (x%i == 0 && y%i == 0)
//		{
//			max = i;
//		}
//		i++;
//	}
//	return max;
//}
//
//int main()
//{
//	int n, a, c;
//	while (cin >> n >> a)
//	{
//		c = a; //cΪС�׵�ǰ����ֵ
//		vector<int> v(n);
//		while (n--)
//		{
//			int a = 0;
//			cin >> a;
//			v.push_back(a);
//		}
//
//		for (int i = 0; i < v.size(); i++)//��ʼѭ�����
//		{
//			if (v[i] <= c)
//			{
//				c += v[i];
//			}
//			else
//			{
//				c += MaxFactor(c, v[i]);
//			}
//
//		}
//		cout << c << endl;
//	}
//	system("pause");
//	return 0;
//}
