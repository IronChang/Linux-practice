#include<iostream>
using namespace std;

//˼·1��������ת��Ϊ�ַ�����Ȼ������жϣ�������Ҫ�ķѿռ�
//˼·2��ֱ�ӽ���ֵ������ת����ԭ�������ֽ��бȽϣ�����תһ�����ȫ����ת�� 
 
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
