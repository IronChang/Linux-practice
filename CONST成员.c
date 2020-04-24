#include<iostream>
using namespace std;
/*
Const修饰类的成员函数
其实就是修饰该成员函数隐含的this指针，
表明该成员函数不能对类的任何成员进行修改 
*/ 



class Date
{
	public:
		void Display()
		{
			cout<<"Display ()" <<endl;
            cout<<"year:" <<_year<< endl;
            cout<<"month:" <<_month<< endl;
			cout<<"day:"<<_day<<endl;	
		}
		void Display() const
		{
			cout<<"Display ()" <<endl;
            cout<<"year:" <<_year<< endl;
            cout<<"month:" <<_month<< endl;
			cout<<"day:"<<_day<<endl;			
		}
	private:
		int _year;
		int _month;
		int _day;
	
};
int main()
{
	Date d1;
	d1.Display();
	const Date d2;
	d2.Display();
}

/*
取地址及const取地址操作符重载 
*/
class Date1
{
	public:
		Date1* operator&()
		{
			return this;
		}
		const Date1* operator&() const
		{
			return this;
		}
	private:
		int _year;
		int _month;
		int _day;
};

