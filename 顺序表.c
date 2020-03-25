
#include<stdio.h>
#include<assert.h>
#include<iostream>
using namespace std;

#define SeqList1 XSeqList1

//动态顺序表
typedef int SLDataType;
class SeqList1
	{
	public:
		SeqList1();
		~SeqList1();
		void CheckCapacity();
		void SeqListPushBack(SLDataType x);
		void SeqListPopBack();
		void SeqListPushFront(SLDataType x);
		void SeqListPopFront();
		void SeqListFind(SLDataType x);
		void SeqListInsert(size_t pos, SLDataType x);
		void SeqListErase(size_t pos);
		void SeqListRemove(SLDataType x);
		void SeqListModify( size_t pos, SLDataType x);
		void SeqListPrint();
		bool  SeqListEmpty()
		{
			return 0 == this->size;
		}
	private:
		SLDataType* array;//动态开辟数组
		size_t size;//有效元素个数
		size_t capacity;//空间大小
	};


#include"test.h"

SeqList1::SeqList1()//初始化顺序表
{
	//this->array = new SLDataType[10];
	this->array = (SLDataType*)malloc(sizeof(SLDataType)* 10);
	//使用malloc后一定注意判断申请是否成功
	if (this->array == NULL)
	{
		perror("malloc失败");
	}
	this->capacity = 10;
	this->size = 0;
}

SeqList1 :: ~SeqList1()//销毁顺序表
{
	//delete[]this->array;
	if (this->array)
	{
		free(this->array);
		this->array = NULL;
	}
	this->capacity = this->size = 0;
}

void SeqList1::CheckCapacity()//检测函数容量
{
	if (this->size == this->capacity)//满了
	{
		int newcapacity = this->capacity * 2;

		SLDataType* temp = new SLDataType[newcapacity];

		memcpy(temp, this->array, this->size*sizeof(SLDataType));

		delete[]this->array;
		this->array = temp;
		this->capacity = newcapacity;
	}
}

void SeqList1::SeqListPushBack(SLDataType x)
{
	//检测容量
	this->CheckCapacity();

	this->array[this->size] = x;
	this->size++;
}

void SeqList1::SeqListPopBack()
{
	this->size--;
}

void SeqList1::SeqListPushFront(SLDataType x)
{
	this->CheckCapacity();

	//然后将数据统一向后移动一位

	int i = 0;
	for (i = this->size - 1; i >= 0; i--)
	{
		this->array[i + 1] = this->array[i];
	}

	this->array[0] = x;
	this->size++;
}

void SeqList1::SeqListPrint()
{

	cout << "顺序表中元素:";
	if (this->array == NULL)
	{
		cout << "NULL" << endl;
		return;
	}
	for (size_t i = 0; i < this->size; i++)
	{
		cout << this->array[i] << " ";
	}
	cout << endl;
}

void SeqList1::SeqListPopFront()
{
	for (int i = 1; i < this->size; i++)
	{
		this->array[i - 1] = this->array[i];
	}
	this->size--;
}

void SeqList1::SeqListFind(SLDataType x)
{
	for (int i = 0; i < this->size; i++)
	{
		if ((*this).array[i] == x)
		{
			cout << "元素"<<x<<"下标为:" << i << endl;
			break;
		}
	}
}

void SeqList1::SeqListInsert(size_t pos, SLDataType x)
{
	this->CheckCapacity();

	//判断pos位置是否合法
	if (pos <0 || pos>this->size)
	{
		cout << "位置非法" << endl;
		return;
	}

	for (int i = this->size-1; i >= pos ; --i)//必须从前先后挪，不然就覆盖了后面的值
	{
		this->array[i + 1] = this->array[i];
			
	}
	this->array[pos] = x;
	this->size++;
}


void SeqList1::SeqListErase(size_t pos)
{
	//判断pos位置是否合法
	if (pos <0 || pos>this->size)
	{
		cout << "位置非法" << endl;
		return;
	}

	for (int i = pos + 1; i < this->size; i++)
	{
		this->array[i - 1] = this->array[i];
	}

	this->size--;
}

void SeqList1::SeqListRemove(SLDataType x)
{
	this->SeqListErase(x);
}

void SeqList1::SeqListModify(size_t pos, SLDataType x)
{
	if (pos <0 || pos>this->size)
	{
		cout << "位置非法" << endl;
		return;
	}

	this->array[pos] = x;
}
int main()
{
	SeqList1 sq;
	sq.SeqListPushBack(1);
	sq.SeqListPushBack(2);
	sq.SeqListPushBack(3);
	sq.SeqListPushBack(4);
	sq.SeqListPushBack(5);
	sq.SeqListPushBack(6);
	sq.SeqListPrint();
	//sq.SeqListPopBack();
	//sq.SeqListPrint();
	//sq.SeqListPushFront(0);
	//sq.SeqListPrint();
	//sq.SeqListPopFront();
	//sq.SeqListPrint();
	//sq.SeqListFind(5);
	sq.SeqListInsert(2, 7);
	sq.SeqListPrint();
	sq.SeqListErase(2);
	sq.SeqListPrint();
	sq.SeqListRemove(6);
	sq.SeqListPrint();
	sq.SeqListModify(0, 2);
	sq.SeqListPrint();
	cout << sq.SeqListEmpty() << endl;

	system("pause");
	return 0;
}



