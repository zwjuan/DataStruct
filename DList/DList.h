#pragma once

#include<stdlib.h>
#include<iostream>
#include<assert.h>

using namespace std;

typedef int DataType;

struct ListNode
{
	ListNode* _next;
	ListNode* _prev;
	DataType _data;
	ListNode(const DataType& x)
		:_data(x)
		,_next(NULL)
		,_prev(NULL)
	{}
};

class List
{
	typedef ListNode Node;
public:
	List();
	~List();
	void Clear();

	List(const List& l);
	List& operator=(List l);

	void PushBack(const DataType& x);
	void PopBack();
	void Print();

    void PushFront(const DataType& x);
	void PopFront();
	void Insert(Node* pos,const DataType& x);
	void Erase(Node* pos);
	Node* Find(const DataType& x);

	void Reverse();

private:
	Node* _head;
	Node* _tail;
};