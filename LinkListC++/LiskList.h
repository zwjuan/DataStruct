#pragma once

#include<iostream>
#include<stdlib.h>
#include<assert.h>

using namespace std;	

typedef int DataType;
//无头结点的单链表
struct SListNode //注：c++中SListNode相当于类名，可以直接使用
{
	DataType _data;
	SListNode * _next;
    SListNode(const DataType& x)
		:_data(x)
		,_next(NULL)
	{}
};

class SList
{
	typedef SListNode Node;

public:
	SList();
	~SList();
	void PushBack(const DataType& x);
	void PopBack();
	void Print();

	void Insert(Node* pos,const DataType& x);
	void Erase(Node* pos);
	Node* Find(const DataType& x);

	void PushFront(const DataType& x);
	void PopFront();

	void SList::clear();
    void copy(Node* head);


	//赋值运算符的重载 ( L1 = L2 )
	//传统写法
	SList& operator = (const SList& l); 
	//现代写法
	//SList& operator = (const SList l);
	//拷贝构造L2(L1)
	SList(const SList& l);


private:
	Node* _head;
	Node* _tail;
};


