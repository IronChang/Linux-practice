// write your code here cpp
//https://www.nowcoder.com/questionTerminal/286af664b17243deb745f69138f8a800?orderByHotValue=1&page=4&onlyReference=false
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s_table, s_cus;
	while (getline(cin, s_table))
	{
		getline(cin, s_cus);

		if (s_table[s_table.size() - 1] != '"')
			s_table.push_back(',');

		string tmp;
		int flag = 0;
		for (int i = 0; i < s_table.size(); i++)
		{	
			if (s_table[i] == '"')
			{	
				++i;
				while (s_table[i] != '"')
				{
					tmp += s_table[i];
					i++;
				}

				if (tmp == s_cus)
				{
					flag = 1;
					break;
				}
				else
				{
					tmp.clear();
					++i; 
					continue;
				}				
			}
			else
			{	
				while (s_table[i] != ',')
				{
					tmp += s_table[i];
					i++;
				}

				if (tmp == s_cus)
				{
					flag = 1;
					break;
				}
				else
				{
					tmp.clear();
					continue;
				}
			}
		}
		if (flag == 0)
			cout << "Important!" << endl;
		else
			cout << "Ignore" << endl;
	}
	return 0;
}