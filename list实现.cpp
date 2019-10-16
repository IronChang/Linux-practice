/*************************************************************************
	> File Name: main.cpp
	> Author: TianChang
	> Mail: 408662026@qq.com
	> Created Time: 2019年10月16日 星期三 16时18分41秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

namespace tc
{
	template<class T>//链表节点类模板
	struct _list_node
	{
		_list_node<T>* _next;
		_list_node<T>* _prev;
		T _data;
		
		_list_node(const T& x)
			:_next(nullptr)
			,_prev(nullptr)
			,_data(x)
		{}
	};

	template<class T>
	struct _list_iterator
	{
		typedef _list_node<T> node;
		
		node* _node;//成员变量

		_list_iterator(node* node)//构造函数
			:_node(node)
		{}

		//重载* 进行访问节点中的值，返回值加上引用既可以将原来的可读
		//变成现在的可读、可写；另一个是减少一次复制提高效率
		T& operator*()
		{
			return _node->_data;
		}

		_list_iterator<T>& operator++()//重载后置++
		{
			_node = _node->_next;
			return *this;
		}

		_list_iterator<T>& operator++(int)//重载前置++
		{
			_list_iterator<T> tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		bool operator!=(const _list_iterator<T>& it)
		{
			return _node != it._node;
		}
	};

	template<class T>//list模板实现
		class list
		{
			typedef _list_node<T> node;//将节点类型进行重新命名方便实用
			public:
			typedef _list_iterator<T> iterator;

			iterator begin()
			{
				return iterator(_head->_next);
			}

			iterator end()
			{
				return iterator(_head);
			}

			list()//构造函数
			{
				_head = new node(T());
				_head->_next = _head;
				_head->_prev = _head;
			}

			void push_back(const T& x)
			{
				node* tail = _head->_prev;
				node* newnode = new node(x);

				//进行插入
				tail->_next = newnode;
				newnode->_prev = tail;
				newnode->_next = _head;
				_head->_prev = newnode;
			}	

			void pop_back()
			{
				node* tmp = _head->_prev;
				//判断链表是否为空
				if (tmp != _head)
				{
					_head->_prev =tmp->_prev;
					tmp->_prev->_next = _head;
					delete[] tmp;
				}
			}

			void push_front(const T& x)
			{
				node* newnode = new node(x);
				node* tmp = _head->_next;

				_head->_next = newnode;
				newnode->_next = tmp;
				tmp->_prev = newnode;
				newnode->_prev = _head;
			}

			void pop_front()
			{
				node* tmp = _head->_next;

				if (tmp != _head)
				{
					_head->_next = tmp->_next;
					tmp->_next->_prev = _head;
					delete[] tmp;
				}
			}

			iterator insert(iterator pos,const T& x)
			{
				node* newnode = new node(x);
				node* tmp =pos._node;

				tmp->_prev->_next = newnode;
				newnode->_prev = tmp->_prev;
				newnode->_next = tmp;
				tmp->_prev = newnode;

				return iterator(newnode);
			}

			iterator erase(iterator pos)
			{
				node* tmp = pos._node;
				node* ret = tmp->_next;

				tmp->_prev->_next = ret;
				ret->_prev = tmp->_prev;
				delete[] tmp;

				return iterator(ret);
			}

			void Swap(const list<T>& l)
			{
				swap(this->_head, l._head);
			}

			void clear()
			{
				node* tmp = _head->_next;
				while (tmp != _head)
				{
					_head->_next = tmp->_next;
					delete[] tmp;
					tmp = _head->_next;
				}

				_head->_next = _head;
				_head->_prev = _head;

			}

			private: 
				node* _head;
		};

		void test()
		{
			list<int> l;
			l.push_back(1);
			l.push_back(2);
			l.push_back(3);
			l.push_back(4);
			l.pop_back();
			l.push_front(0);
			l.push_front(00);
			l.pop_front();
	        l.clear();
			list<int>::iterator is = l.begin();
			l.insert(is, 50);
			
			list<int>::iterator f = l.begin();
			l.erase(f);

			list<int>::iterator it = l.begin();
			while (it != l.end())
			{
				cout << *it << " ";
				++it;
			}
			cout << endl;

		
		}
}





int main()
{
	tc::test();
	system("pause");
	return 0;
}
