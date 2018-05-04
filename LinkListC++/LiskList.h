#pragma once

#include<iostream>
#include<stdlib.h>
#include<assert.h>

using namespace std;	

typedef int DataType;
//��ͷ���ĵ�����
struct SListNode //ע��c++��SListNode�൱������������ֱ��ʹ��
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


	//��ֵ����������� ( L1 = L2 )
	//��ͳд��
	SList& operator = (const SList& l); 
	//�ִ�д��
	//SList& operator = (const SList l);
	//��������L2(L1)
	SList(const SList& l);


private:
	Node* _head;
	Node* _tail;
};


