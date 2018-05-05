#pragma once

#include<iostream>
#include<assert.h>
#include<string>

using namespace std;

template<class T>
struct ListNode
{
	T _data;
	ListNode* _next;
	ListNode* _prev;

	ListNode(const T& x)
		:_data(x)
		,_next(NULL)
		,_prev(NULL)
	{}
};

template<class T>
class List
{
	typedef ListNode<T> Node;

public:
	List()
		:_head(new Node(T()))
	{
		_head->_prev = _head;
		_head->_next = _head;
	}

	~List()
	{
		Clear();
		delete _head;
		_head = NULL;
	}

	void Clear()//删除除头结点的结点
	{
		Node* cur = _head->_next;
		while(cur != _head)
		{
			Node* next = cur->_next;
			delete cur;
			cur = next;
		}
		_head ->_next = _head;
		_head ->_prev = _head;
	}

	//拷贝构造
	List(const List& l);

	List& operator=(const List& l)
	{
		swap(_head,l._head);
		return *this;
	}

	void PushBack(const T& x);
	void PopBack();
	bool Empty()
	{
		return _head->_next == _head;
	}
	void PushFront(const T& x);
	void PopFront();

	void Insert(Node* pos, const T& x);
	void Erase(Node* pos);
	Node* Find(const T& x)
	{
		Node* cur = _head->_next ;

		while(cur != _head)
		{
			if(cur->_data == x)
			{
				return cur;
			}
			cur = cur->_next;
		}
		return cur; //相当于返回头结点
	}
	
	void Print();

private:
	Node* _head;

}; 

//l1(l2);
template<class T>
List<T>::List(const List& l)
	:_head(new Node(T()))
{
	_head ->_next = _head;
	_head->_prev = _head;

	Node* cur = l._head ->_next ;
	while(cur != l._head)
	{
		this->PushBack (cur->_data );
		cur = cur->_next ;
	}
}

//l1 = l2
//template<class T>
//List& List<T>::operator=(const List l)
//{
//	swap(_head,l._head);
//	return *this;
//}


template<class T>
void List<T>::PushBack(const T& x)
{
	/*Node* newNode = new Node(x);
	Node* tail = _head->_prev;

	tail->_next = newNode;
	newNode->_prev = tail;
	newNode->_next = _head;
	_head->_prev = newNode;*/
	
	Insert(_head,x);
}

template<class T>
void List<T>::PopBack()
{
	//assert(!Empty());//首先应判断是否为NULL
	//Node* tail = _head->_prev ;
	//Node* prev = tail->_prev ;
	//delete tail;

	//prev->_next = _head;
	//_head ->_prev = prev;

	Erase(_head->_prev );
}

template<class T>
void List<T>::PushFront(const T& x)
{
	/*Node* newNode = new Node(x);
	Node* next = _head->_next ;

	newNode->_next = next;
	next->_prev = newNode;

	newNode->_prev = _head;
	_head->_next = newNode;*/

	Insert(_head->_next,x );

}

template<class T>
void List<T>::PopFront()
{
	/*assert(!Empty());
	Node* next = _head->_next ;
	Node* nextnext = next->_next ;
    
	delete next;

	_head->_next = nextnext;
	nextnext->_prev = _head;*/

	Erase(_head->_next );
}

//template<class T>
//Node* List<T>::Find(const T& x)//?????
//{
//	Node* cur = _head->_next ;
//
//	while(cur != _head)
//	{
//		if(cur->_data == x)
//		{
//			return cur;
//		}
//		cur = cur->_next;
//	}
//	return cur; //相当于返回头结点
//}

template<class T>
void List<T>::Insert(Node* pos, const T& x)
{
	assert(pos);
	Node* newNode = new Node(x);
	Node* prev = pos->_prev;

	prev->_next = newNode;
	newNode->_prev = prev;
	newNode->_next = pos;
	pos->_prev = newNode;
}

template<class T>
void List<T>::Erase(Node* pos)
{
	assert(pos && pos != _head);

	Node* prev = pos->_prev ;
	Node* next = pos->_next ;

	delete pos;

	prev->_next = next;
	next->_prev = prev;
}

template<class T>
void List<T>::Print()
{
	Node* cur = _head->_next ;
	while(cur != _head)
	{
		cout<<cur->_data <<endl;
		cur = cur->_next ;
	}
}