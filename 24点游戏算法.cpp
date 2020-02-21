


#include<iostream>
#include<vector>
using namespace std;
bool is24(vector<double> a, int tot, double result)
{
    if(a.empty())
    {
        return result==tot;
    }
    for(int i=0; i<a.size() ;i++)
    {
        vector<double> b(a);
        b.erase(b.begin()+i);
        if(is24(b,tot,result+a[i])
           || is24(b,tot,result-a[i])
           || is24(b,tot,result*a[i])
           || is24(b,tot,result/a[i]))
            return true;
    }
    return false;
}
int main()
{
    vector<double> a(4,0);
    while(cin >> a[0] >> a[1] >> a[2] >> a[3])
    {
        if(is24(a,24,0))
            cout<<"true"<<endl;
        else cout<<"false"<<endl;
    }
}