#include<iostream>
using namespace std;

int Search_Money(int num)
{
    if(num == 1)
        return 0;
    if(num <= 3)
        return 1;
    else
        return Search_Money((num+2)/3)+1;
}

int main()
{
	int num;
	while (cin >> num && num!=0)
	{

		cout << Search_Money(num) << endl;
	}
	return 0;
}

