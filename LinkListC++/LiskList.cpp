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
	_head = _tail = NULL;//��ͷ����β�����ΪNULL

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
	if(_head == NULL)//������
	{
		return ;
	}
	else if(_head->_next  == NULL)//ֻ��һ�����
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
		cur->_next = NULL;//ע���ÿ�cur->next 
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
	cout<<endl;  //������ֱ�ӻ���
}

//S1=S2  ���ͷ�L1�ٿ���L2
SList& SList::operator = (const SList& l)//��ͳд��
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
	:_head(NULL)//һ��Ҫ��ʼ��
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
