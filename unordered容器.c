#define _CRT_SECURE_NO_WARNINGS 1
#include<unordered_set>
#include<iostream>
#include<set>
#include<time.h>
#include<vector>
using namespace std;

void test1()
{


	std::unordered_set<int> uset;
	uset.insert(4);
	uset.insert(3);
	uset.insert(7);
	uset.insert(1);
	
	std::set<int> set;
	set.insert(4);
	set.insert(3);
	set.insert(7);
	set.insert(1);



	cout << "unordered_set元素：";
	for (auto e : uset)
	{
		cout << e << " ";
	}
	cout << endl;

	cout << "set元素：";
	for (auto e : set)
	{
		cout << e << " ";
	}
	cout << endl;


}

void test2()
{
	srand(time(0));

	int n = 10000000;
	std::vector<int> v;
	v.reserve(n);

	for (int i = 0; i < n; i++)
	{
		v.push_back(rand());
	}

	int start1 = clock();
	std::unordered_set<int> uset;
	for (auto e : v)
	{
		uset.insert(e);
	}
	int end1 = clock();

	cout << "unordered_set效率" << end1 - start1 << endl;

	int start2 = clock();

	set<int> set;
	for (auto e : v)
	{
		set.insert(e);
	}
	int end2 = clock();
	cout << "set效率" << end2 - start2 << endl;

}

int main()
{
	//test1();
	test2();
	system("pause");
	return 0;
}
