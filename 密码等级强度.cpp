
#include <iostream>
#include <string>
using namespace std;

//检查字母：没有返回0；全部大(小)写返回10；大小写混合返回20
int AboutLetter(const string& s,int length)
{
	int big = 0, small = 0;
	for (int i = 0; i < length; ++i)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			++small;
		else if (s[i] >= 'A' && s[i] <= 'Z')
			++big;
	}
	if ((small + big) == 0)
		return 0;
	else if (small == length || big == length)
		return 10;
	else if (small > 0 && big > 0)
		return 20;
	return 0;
}

//检查数字个数：没有返回0；有一个返回10；大于一个返回20
int NumOfNumber(const string& s, int length)
{
	int count = 0;
	for (int i = 0; i < length; ++i)
	{
		if (s[i] >= '0' && s[i] <= '9')
			++count;
	}
	if (0 == count)
		return 0;
	else if (1 == count)
		return 10;
	else
		return 20;
}

//检查符号个数：没有返回0；有一个返回10；大于一个返回25
int NumOfSymbol(const string& s, int length)
{
	int count = 0;
	for (int i = 0; i < length; ++i)
	{
		//不是数字也不是字母的话就是符号了
		if (!(s[i] >= '0' && s[i] <= '9')&&
			!(s[i] >= 'a' && s[i] <= 'z')&&
			!(s[i] >= 'A' && s[i] <= 'Z'))
			++count;
	}
	if (0 == count)
		return 0;
	else if (1 == count)
		return 10;
	else
		return 25;
}

int main()
{
	int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;
	string s;
	while (getline(cin, s))
	{
		int length = s.size();
		//sum1保存密码长度的分数
		if (length <= 4)
			sum1 = 5;
		else if (length <= 7)
			sum1 = 10;
		else
			sum1 = 25;

		sum2 = AboutLetter(s, length);//sum2保存字母的分数
		sum3 = NumOfNumber(s, length);//sum3保存数字的分数
		sum4 = NumOfSymbol(s, length);//sum4保存符号的分数

		//sum5保存奖励分
		if (sum2 > 0 && sum3 > 0)
		{
			if (sum4 > 0)
			{
				if (20 == sum2)
					sum5 = 5;
				else
					sum5 = 3;
			}
			else
				sum5 = 2;
		}

		//根据得分情况对应输出安全等级
		if (sum1 + sum2 + sum3 + sum4 + sum5 >= 90)
			cout << "VERY_SECURE" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 80)
			cout << "SECURE" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 70)
			cout << "VERY_STRONG" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 60)
			cout << "STRONG" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 50)
			cout << "AVERAGE" << endl;
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 25)
			cout << "WEAK" << endl;
		else
			cout << "VERY_WEAK" << endl;
	}
	return 0;
}


