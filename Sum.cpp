#include<iostream>
using namespace std;

class Sum
{
	static int _sum;
	static int _i;
public:
	Sum()
	{
		_sum += _i;
		++_i;
	}

	static int& getsum()
	{
		return _sum;
	}

	int sum_solution(int n)
	{
		Sum::_sum = 0;
		Sum::_i = 1;
		new Sum[n];
		return Sum::getsum();
	}
};

int Sum::_i = 1;
int Sum::_sum = 0;
int main()
{
	Sum s;
	cout << s.sum_solution(3) << endl;

	system("pause");
	return 0;
}
