/*************************************************************************
	> File Name: vector.cpp
	> Author: TianChang
	> Mail: 408662026@qq.com 
	> Created Time: 2019年10月20日 星期日 16时11分40秒
 ************************************************************************/

#include<iostream>
#include<string.h>
#include<assert.h>
using namespace std;

template<class T>
class vector
{
	public:
		typedef T* iterator;
		//无参构造函数、迭代器构造函数、初始化n个值为val的
		vector()//构造函数
			:_start(NULL)
			,_finish(NULL)
			,_end_of_storage(NULL) 
		{}

		vector(const vector<T>& v)//拷贝构造函数
		{
			_start = new T[v.size()];
			memcpy(_start,v._start,sizeof(T)*v.size());
			_finish = _start + v.size();
			_end_of_storage = _start + v.size();
		}

		vector<T>& operator=(vector<T> v)//重载复制运算符 现代写法
		{
			Swap(v);
			return *this;
		}

		~vector()
		{
			if(_start)
			{
				delete[] _start;
				_start = _finish = _end_of_storage = NULL;
			}
			//cout<<"~vector"<<endl;
		}

		void Swap(vector<T>& v)
		{
			swap(_start,v._start);
			swap(_finish,v._finish);
			swap(_end_of_storage,v._end_of_storage);
		}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _end_of_storage - _start;
		}

		bool empty()
		{
			return _start != _finish;
		}

		void resize(size_t n,const T& val = T())
		{
			if(n<size())
			{
				_finish = _start + n;
			}
			else
			{
				if(n>capacity())
				{
					reserve(capacity()*2);
				}

				while(_finish != _start + n)
				{
					*_finish++ = val;
				}
			}
		}

		void reserve(size_t n)
		{
			if(n>capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];
				if(_start)
				{
					memcpy(tmp,_start,sizeof(T)*sz);
					delete[] _start;
				}

				_start = tmp;
				_finish = _start + sz;
				_end_of_storage = _start + n;
			}
		}

		void push_back(const T& x)
		{
			if(_finish == _end_of_storage)
			{
				int newcapacity = capacity()==0?2:capacity()*2;
				reserve(newcapacity);
			}

			*_finish++ = x;
		}

		void pop_back()
		{
			assert(_finish > _start);
			--_finish;
		}
		//考虑增容和插入和删除时的迭代器失效
		void insert(iterator pos,const T& x)
		{
			if(_finish == _end_of_storage)
			{
				size_t n = pos - _start;
				size_t newcapacity = capacity()==0?2:capacity()*2;
				reserve(newcapacity);
				pos = _start + n;//防止迭代器失效
			}
			iterator end = _finish - 1;
			while(end >= pos)
			{
				*(end+1)=*end;
				--end;
			}
			*pos = x;
		 	++_finish;
		}

		void erase(iterator pos)
		{
			iterator begin = pos +1;
			while(begin < _finish)
			{
				*(begin-1)=*begin;
				++begin;
			}
			--_finish;
		}

		T& operator[](size_t pos)
		{
			return _start[pos];
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
};

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
//	v.insert(0,6);
	vector<int>::iterator is = v.end();
	v.erase(is);
	cout<<v.empty()<<endl;
	vector<int>::iterator it = v.begin();
	while(it != v.end())
	{
		cout<<*it<<" ";
		++it;
	}
	cout<<endl;
	int i = 0;
	for(i;i<v.size();++i)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;

	return 0;
}

