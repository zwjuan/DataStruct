#include"DList.h"

List::List()
	:_head(NULL)
	,_tail(NULL)
{}


void List::Clear()
{
	Node* cur = _head;
	while(cur)
	{
		Node* next = cur->_next ;
		delete cur;
		cur = next;
	}
	_head = _tail = NULL;
}
List::~List()
{
	Clear();
}

void List::PushBack(const DataType& x)
{
	if(_head == NULL)//无节点
	{
		_head = new Node(x);
		_tail = _head;
	}
	else
	{
		Node* tmp = new Node(x);
		_tail->_next = tmp;
		tmp->_prev = _tail;

		_tail = tmp;
	}
}

void List::PopBack()
{
	//if(_head == NULL) //无节点
	//{
	//	return ;
	//}
	//else if(_head->_next == NULL) //一个结点
	//{
	//	delete _tail;
	//	_head = _tail = NULL;
	//}
	//else
	//{
	//	Node* prev = _tail->_prev ;

	//	delete _tail;
	//	prev->_next = NULL;
	//	_tail = prev;
	//}
	Erase(_tail);
}


void List::Print()
{
	Node* cur = _head;
	while(cur)
	{
		cout<<cur->_data <<" ";
		cur = cur->_next ;
	}

	cout<<endl;
}

void List::PushFront(const DataType& x)
{
	/*Node* NewNode = new Node(x);
	_head->_prev = NewNode;
	NewNode->_next = _head;
	_head = NewNode;*/

	Insert(_head,x);
}

void List::PopFront()
{
	/*if(_head == NULL)
	{
		return ;
	}
	else if(_head->_next == NULL )
	{
		delete _tail;
		_tail = _head = NULL;
	}
	else
	{
		Node* head = _head->_next ;
		delete _head;
		head->_prev = NULL;
		_head = head;
	}*/

	Erase(_head);
}

void List::Insert(Node* pos,const DataType& x)
{
	//空链表、一个结点、一般情况
	Node* NewNode = new Node(x);
	if(_head == pos)
	{
		if(_head == NULL)
		{
			_head = _tail = NewNode;
		}
		else
		{
			NewNode->_next = _head;
			_head->_prev = NewNode;
			_head = NewNode;
		}
	}
	else 
	{
		Node* prev = pos->_prev ;
		prev->_next = NewNode;
		NewNode->_prev = prev;
		NewNode->_next = pos;
		pos->_prev = NewNode;
	}
}

void List::Erase(Node* pos)
{
	//头删、尾删、一般情况、NULL、一个结点
	if(_head == _tail)//一个结点
	{
		assert(_head);
		_head = _tail = NULL;
	}
	else if(pos == _head)//头删
	{
		_head = _head ->_next ;
		_head ->_prev = NULL;
	}
	else if(pos == _tail)//尾删
	{
		Node* tmp = _tail->_prev ;
		tmp->_next = NULL;
		_tail = tmp;
	}
	else //一般情况
	{
		Node* prev = pos->_prev ;
		Node* next = pos->_next ;
		prev->_next = next;
		next->_prev = prev;
	}
	delete pos;
}

List::Node* List::Find(const DataType& x)
{
	Node* cur = _head;
	while(cur)
	{
		if(cur->_data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->_next ;
		}
	}
	return NULL;
}

//l1(l2)
List::List(const List& l)
	:_head(NULL)
	,_tail(NULL)
{
	Node* cur = l._head;
	while(cur)
	{
		PushBack (cur->_data );
		cur = cur->_next ;
	}

}


//l1 = l2
List& List::operator=(List l)
{
	swap(_head, l._head);
	swap(_tail, l._tail);
	return *this;
}

