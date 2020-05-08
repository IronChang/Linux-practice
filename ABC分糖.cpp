#include<iostream>
using namespace std;

int main()
{
	//ÊäÈëA-B,B-C,A+B,B+C
	int a, b, c, d;
	cin >> a >> b >> c >> d;
 
	int A = (a + c) / 2;
	int C = (d - b) / 2;
 
	int B1 = (c - a) / 2;
	int B2 = (b + d) / 2;
 
	if (B1 != B2)
	{
		cout << "No" << endl;
	}
	else
	{
		cout << A << " " << B1 << " " << C << endl;
	}
    return 0;
}
