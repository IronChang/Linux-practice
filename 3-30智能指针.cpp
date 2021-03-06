#include <iostream>
using namespace std;

//void Test()
//{
//	int* p1 = new int[10]; // 他们也可以能会抛异常
//	int* p2 = new int[20];
//	int* p3 = new int[30];
//	try
//	{
//		// ...
//		func(); // 可能会抛异常
//	}
//	catch (...)
//	{
//		// ...
//		delete[] p1;
//		delete[] p2;
//		delete[] p3;
//
//		throw;
//	}
//
//	delete[] p1;
//	delete[] p2;
//	delete[] p3;
//}
//
//int main()
//{
//	//Test();
//
//	return 0;
//}

// 核心思想就是RAII
template<class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{}

	~SmartPtr()
	{
		cout <<"delete[]:" <<_ptr << endl;
		delete[] _ptr;
	}
private:
	T* _ptr;
};

//void Test()
//{
//	//int* p1 = new int;
//	//SmartPtr<int> sp1(p1);
//	SmartPtr<int> sp1(new int);
//
//	// ...
//	throw out_of_range("越界");
//
//	//delete p1;
//}

//void Test()
//{
//	SmartPtr<int> sp1(new int[10]);
//	SmartPtr<int> sp2(new int[20]);
//	SmartPtr<int> sp3(new int[30]);
//
//	// ...
//	// func();
//	throw out_of_range("越界");
//}
//
//int main()
//{
//	try
//	{
//		Test();
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	catch (...)
//	{
//		cout << "未知异常" << endl;
//	}
//
//	return 0;
//}

// 智能指针的版本及发展历史？
// C++98 auto_ptr

// 1.RAII管理资源
// 2.能够像指针一样去使用
namespace bit
{
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr)
			:_ptr(ptr)
		{}

		// copy(ap1)
		auto_ptr(auto_ptr<T>& ap)
			: _ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}

		// ap1 = ap2;
		auto_ptr<T>& operator=(auto_ptr<T>& ap)
		{
			if (this != &ap)
			{
				if (_ptr)
					delete _ptr;

				_ptr = ap._ptr;
				ap._ptr = nullptr;
			}

			return *this;
		}

		~auto_ptr()
		{
			if (_ptr)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
			}
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
	private:
		T* _ptr;
	};

	struct A
	{
		int _a1;
		int _a2;
	};

	void test_auto_ptr1()
	{
		int* p1 = new int;
		*p1 = 10;

		auto_ptr<int> ap1(new int);
		*ap1 = 10;

		A* pa = new A;
		(*pa)._a1 = 10;
		pa->_a1 = 20;

		auto_ptr<A> apa(new A);
		(*apa)._a1 = 10;
		//apa->->_a2 = 20;  本来应该是这样，编译器为了语法可读性，省略了一个箭头
		apa->_a2 = 20;
	}

	void test_auto_ptr2()
	{
		auto_ptr<int> ap1(new int);
		auto_ptr<int> copy(ap1);  // ap1拷贝构造了一个copy对象，管理权转给copy
		auto_ptr<int> copy1 = copy; // 拷贝构造copy1，管理权转给copy1 

		// 这样的方式的问题是什么呢？
		*ap1 = 10;  // 悬空，访问会崩溃
	}


	// C++11  简单粗暴，直接不让拷贝
	template<class T>
	class unique_ptr
	{
	public:
		unique_ptr(T* ptr)
			:_ptr(ptr)
		{}

		~unique_ptr()
		{
			if (_ptr)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
			}
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		// 以下两种方式：任选一种都可以
		// C++11 防拷贝
		//unique_ptr(const unique_ptr<T>&) = delete;
		//unique_ptr<T>& operator=(const unique_ptr<T>&) = delete;
	private:
		// C++98 防对象拷贝实现方式：只声明不实现+声明成私有
		unique_ptr(const unique_ptr<T>&);
		unique_ptr<T>& operator=(const unique_ptr<T>&);
	private:
		T* _ptr;
	};

	void test_unique_ptr()
	{
		unique_ptr<int> up1(new int);
		//unique_ptr<int> copy(up1);
	}

	// 如果是私有以后，别人实现了也调不动
	//template<class T>
	//unique_ptr<T>::unique_ptr(const unique_ptr<T>& ap)
	//	:_ptr(ap._ptr)
	//{}

	// C++11 支持拷贝的shared_ptr
	template<class T>
	class shared_ptr
	{
	public:
		// RAII
		shared_ptr(T* ptr)
			:_ptr(ptr)
			, _pCount(new int(1))
		{}

		// copy(sp1)
		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			, _pCount(sp._pCount)
		{
			++(*_pCount);
		}
		
		// sp1 = sp4
		// sp3 = sp4; 本身sp3和sp4就是管理着同一块资源的
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			//if (this != &sp && _ptr != sp._ptr)
			if (_ptr != sp._ptr)
			{
				// 先释放原对象资源
				if (--(*_pCount) == 0)
				{
					delete _pCount;
					if (_ptr)
						delete _ptr;
				}
				_ptr = sp._ptr;
				_pCount = sp._pCount;
				++(*_pCount);
			}

			return *this;
		}

		~shared_ptr()
		{
			if (--(*_pCount) == 0)
			{
				delete _pCount;

				if (_ptr)
				{
					cout << "delete:" << _ptr << endl;
					delete _ptr;
				}	
			}
		}

		// 像指针一样使用
		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
	private:
		T* _ptr;
		int* _pCount; // 引用计数
	};

	void test_shared_ptr()
	{
		shared_ptr<int> sp1(new int);
		shared_ptr<int> copy1(sp1);
		shared_ptr<int> copy2(copy1);

		shared_ptr<int> sp3(new int);
		shared_ptr<int> sp4(sp3);

		sp1 = sp4;
		sp3 = sp4;
	}
}


int main()
{
	//bit::test_auto_ptr2();
	//bit::test_unique_ptr();
	bit::test_shared_ptr();

	return 0;
}
