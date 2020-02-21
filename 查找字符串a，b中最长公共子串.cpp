#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
int main()
{
	string s1;
	string s2;
 
	while(cin>>s1>>s2)
    {
		int len1 = s1.size();
		int len2 = s2.size();
		string tmp;
		string ret;
 
 
		if (len1>len2)
		{
			swap(s1, s2);//±£Ö¤s1ÊÇ¶Ì´®
		}
		int len = s1.size();
		while (len)
		{
			for (int i = 0; i <= s1.size() - len; i++)
			{
				tmp = s1.substr(i, len);
				/*if (strstr(s2.c_str(), tmp.c_str()))
				{
					ret = tmp;
					break;
				}*/
				if (s2.find(tmp) != string::npos)
				{
					ret = tmp;
					break;
				}
			}
			if (ret.size() > 0)
			{
				break;
			}
			len--;
		}
 
		cout << ret << endl;
    }
	return 0;
}
 

