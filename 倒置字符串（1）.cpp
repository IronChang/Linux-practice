#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//����һ��������ת + �ֲ���ת 
int main()
{
	string s;
	getline(cin, s);
	//���������ת
	reverse(s.begin(), s.end());

	//���в�����ת
	string::iterator start = s.begin();
	string::iterator end = start;
	while (end != s.end())
	{
		//�ҿո������ո�ͣ��
		while (end != s.end() && *end != ' ')
		{
			end++;
		}
		
		if (end != s.end())
		{
			reverse(start, end);//���оֲ���ת
			end++;
			start = end;
		}
		else
		{
			reverse(start, end);//���оֲ���ת
		}
	}
	cout << s << endl;

	return 0;
}


//������������cin���������ԣ������ո��ֹͣ
int main()
{
	//����cin�����ո�ͽ���������
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


