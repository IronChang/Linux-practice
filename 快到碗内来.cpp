#include<iostream>
#include<vector>
using namespace std; 
#define PI 3.14;

int main()
{
	vector<double> v(2);
	while (cin >> v[0] >> v[1])
	{
		double  len = 2 * v[1] * PI;
		if (len >= v[0])
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
