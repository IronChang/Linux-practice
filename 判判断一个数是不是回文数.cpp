#include<iostream>
using namespace std;

//思路1：将整数转换为字符串，然后进行判断，但是需要耗费空间
//思路2：直接将数值进行逆转，与原来的数字进行比较，（逆转一半或者全部逆转） 
 
class Solution {
public:
    bool isPalindrome(int x) {
        string s;
        s+=to_string(x);
        int len = s.size();
        for(int i = 0;i<s.size()/2;i++)
        {
            if(s[i] != s[len-1-i])
            return false;
        }
        return true;
    }
};

class Solution {
public:
    bool isPalindrome(int x) {
       if(x < 0)
            return false;
        long num = 0;
        int x1 = x;
        while(x1 > 0)
        {
            num = num*10 + x1 % 10;
            x1 = x1 / 10;
        }
        return num == x;
    }
};

int main()
{
	Solution s;
	int num;
	while(cin>>num)
	{
		cout<<s.isPalindrome(num)<<endl;
	}
	return 0;
}
