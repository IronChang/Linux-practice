#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		
		string res;
		if (strs.size() == 0)
			return res;
	
		string min = strs[0];//找到当前数组中组小的字符串
		for (size_t i = 0; i < strs.size(); i++)
		{
			if (min.size()>strs[i].size())
				min = strs[i];
		}

		for (size_t i = 0; i < min.size(); i++)
		{
			for (size_t j = 0; j < strs.size(); j++)
			{
				if (min[i] != strs[j][i])
					return res;
			}
			res += min[i];
		}
		return res;
	}
};

int main()
{
	Solution s;
	vector<string> strs = { "flower", "flow", "flight" };
	cout << s.longestCommonPrefix(strs) << endl;

	return 0;
}
