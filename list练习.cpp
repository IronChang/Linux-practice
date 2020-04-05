void list_modifiers_4()
{
	//  resize/swap/clear练习
	int arr[] = { 1, 2, 3 };
	list<int> l1(arr, arr + sizeof(arr) / sizeof(arr[0]));
	Print(l1);

	//将l1中元素增加到10，多出的元素用默认值填充
	// (注意：如果list中放置的是内置类型，默认值为0, 如果list中放置自定义类型元素，调用缺省构造函数)
	l1.resize(10);
	Print(l1);

	//将l1中的元素增加到20个，多出来元素用4来填充
	l1.resize(20, 4);
	Print(l1);

	//将l1中的元素减少到五个，因为resize可以改变list的容量，有别于vector中的resize
	l1.resize(5, 100);//初始值没有用
	Print(l1);


	//用容器中的元素来初始化构造list
	vector<int> v{ 4, 5, 6 };
	list<int> l2(v.begin(), v.end());//迭代器初始化
	Print(l2);

	//将l2中的元素清空
	l2.clear();
	cout << l2.size() << endl;
}

void iterator_questions()
{
	//因为list的底层原理是带头双向循环链表，所以在插入时是不会导致list的迭代器失效的，只有在删除时才会失效。并且失效的只有指向被删除节点迭代器。指向其他节点的迭代器正常不会失效。
	//迭代器失效：迭代器指向的节点无效即被删除了

	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	list<int> L(arr, arr + sizeof(arr) / sizeof(arr[0]));

	auto it = L.begin();
	while (it != L.end())
	{
		//L.erase(it);
		//++it;//此时会报错，因为已经删除了it所指向的哪个节点，此时it已经无效。必须从新赋值。改进日下
		//it = L.begin();

		//L.erase(it++);
		//erase()y因为是链表 删除一个节点后会把前一个节点和后摇滚节点连接起来，返回被删除节点的后一个节点的地址迭代器
		it = L.erase(it);
	}
}
