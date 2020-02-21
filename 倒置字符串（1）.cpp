#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//方法一：整体逆转 + 局部逆转 
int main()
{
	string s;
	getline(cin, s);
	//整体进行逆转
	reverse(s.begin(), s.end());

	//进行部分逆转
	string::iterator start = s.begin();
	string::iterator end = start;
	while (end != s.end())
	{
		//找空格，遇见空格停下
		while (end != s.end() && *end != ' ')
		{
			end++;
		}
		
		if (end != s.end())
		{
			reverse(start, end);//进行局部反转
			end++;
			start = end;
		}
		else
		{
			reverse(start, end);//进行局部反转
		}
	}
	cout << s << endl;

	return 0;
}


//方法二：利用cin的输入特性，遇到空格就停止
int main()
{
	//利用cin遇到空格就结束的性质
	string s1;
	string s2;
	cin >> s2;
	while (cin >> s1)
	{
		s2 = s1 + " " + s2;
	}
    cout<<s2<<endl;
	return 0;
} 


