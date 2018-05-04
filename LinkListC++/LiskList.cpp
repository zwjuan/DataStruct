#include"LinkList.h"

SList::SList()
		:_head(NULL)
		,_tail(NULL)
	{}

void SList::clear()
{
	Node* cur = _head;
	while(cur)
	{
		Node* next = cur->_next ;
		delete cur;
		cur = next;
	}
	_head = _tail = NULL;//将头结点和尾结点置为NULL

}

SList::~SList()
{
	clear();
}

void SList::PushBack(const DataType& x)
{
	if(_head == NULL)
	{
		_head = _tail = new Node(x); 
	}
	else
	{
		_tail->_next = new Node(x);
		_tail = _tail->_next ;
	}
}

void SList::PopBack()
{
	//assert(_head);
	if(_head == NULL)//空链表
	{
		return ;
	}
	else if(_head->_next  == NULL)//只有一个结点
	{
		delete _head;
		_head = _tail = NULL;
	}
	else
	{
		Node* cur = _head;
		while(cur->_next != _tail)
		{
			cur = cur->_next ;
		}
		delete _tail;
		cur->_next = NULL;//注：置空cur->next 
		_tail = cur;
	}
}

void SList::Print()
{
	Node* cur = _head;
	while(cur)
	{
		cout<<cur->_data <<" ";
		cur = cur->_next ;
	}
	cout<<endl;  //空链表直接换行
}

//S1=S2  先释放L1再拷贝L2
SList& SList::operator = (const SList& l)//传统写法
{
	if(this != &l)
	{
		clear();
		copy(l._head );
	}
	return *this;
}

//SList& SList::operator=(const SList l)
//{
//	swap(_head,l._head );
//	swap(_tail,l._tail );
//	return *this;
//}

void SList::copy(Node* head)
{
	Node* cur = head;
	while(cur)
	{
		PushBack (cur->_data );
		cur = cur->_next ;
	}
}

SList::SList(const SList& l)
	:_head(NULL)//一定要初始化
	,_tail(NULL)
{
	/*Node* cur = l._head ;
	while(cur)
	{
		PushBack(cur->_data );
		cur = cur->_next ;
	}*/
	copy(l._head );
}

void SList::PushFront(const DataType& x )
{
	Node* NewNode = new Node(x);
	NewNode->_next = _head;
	_head = NewNode;
}

void SList::PopFront()
{
	Node* cur = _head;

	_head = cur->_next ;
	delete cur;
}

void SList::Insert(Node* pos,const DataType& x)
{
	Node* NewNode = new Node(x);
	Node* cur = _head;
	while(cur->_next != pos)
	{
		cur = cur->_next ;
	}
	cur->_next = NewNode;
	NewNode->_next = pos;

}

void SList::Erase(Node* pos)
{
	Node* cur = _head;
	while(cur->_next != pos)
	{
		cur = cur->_next ;
	}
	cur->_next  = pos->_next ;
	delete pos;
}

	
SList::Node* SList::Find(const DataType& x)
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
