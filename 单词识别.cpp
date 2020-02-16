
#include <bits/stdc++.h>

int main()
{
	string str, word = "";
	getline(cin, str);
	transform(str.begin(), str.end(), str.begin(), ::tolower);   //把字符串全部转换成小写
	map<string, int> m;   //map的key为单词,value为这个单词出现的次数
	for (auto it : str)
	{
		if (it == ' ' || it == ',' || it == '.')   //标志着一个单词的结束
		{
			if (word != "")
			{
				m[word]++;
			}
			word = "";    //将word置为空,开始记录下一个单词
		}
		else
		{
			word += it;
		}
	}
	for (auto it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << ":" << it->second << endl;
	}
	return 0;
}