#include<iostream>
using namespace std;
 
class BinInsert {
public:
int binInsert(int n, int m, int j, int i) {
// write code here
return n | (m << j);
}
};

int main()
{
	int m,n,j,i;
	BinInsert r;
	cin>>n>>m>>j>>i;
	cout<<r.binInsert(n,m,j,i)<<endl;
	return 0;
}
