#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{

	//����N��ȡֵ��Χ��2~16
	string ret;
	string table("0123456789ABCDEF");
 
	int M;
	int N;
	cin >> M >> N;
 
	int flag = 1;//Ĭ��������
	if (M < 0)//�����Ǹ���
	{
		flag = 0;
		M = -M;
	}
 
	while (M)
	{
		ret += table[M%N];
		M /= N;
	}
	if (flag == 0)//�Ǹ���
	{
		ret += '-';
	}
	//�÷�תһ���ַ���(֮ǰ�ǴӺ�ǰ���Ŵ��)
	reverse(ret.begin(), ret.end());
	cout << ret << endl;
}
