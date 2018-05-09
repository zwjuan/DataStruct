#pragma once

/*
	在一个排序的链表中，如何删除重复的结点？
	注：头结点可能也重负，所以头结点也有可能被删除
*/
#include <iostream>
using namespace std;

#define DataType int

typedef struct ListNode
{
	DataType _value;
	struct ListNode* _next;

	ListNode(const int& x)
		:_value(x)
		,_next(NULL)
	{}
}Node;

void PushBack(Node** phead, DataType x)
{
	Node* pNew = new Node(x);
	//pNew->_value = x;
	//pNew->_next = NULL;
	if(*phead == NULL)
	{
		*phead = pNew;
	}
	else
	{
		Node* pNode = *phead;
		while(pNode->_next != NULL)
		{
			pNode = pNode->_next;
		}
		pNode->_next = pNew;
	}
}

void DeleteDuplication(Node** head)
{
	if(head == NULL || *head == NULL)
	{
		return ;
	}

	Node *PreNode = NULL;
	Node *cur = *head;
	while(cur != NULL)
	{
		Node *next = cur->_next;
		bool needDelete = false;
		if(next != NULL && cur->_value == next->_value)
		{
			needDelete = true;
		}

		if(!needDelete)
		{
			PreNode = cur;
			cur = next;
		}
		else //需要删除相同的结点
		{
			int value = cur->_value;
			Node *BeDel = cur;
			while(BeDel != NULL && BeDel->_value == value)
			{
				next = BeDel->_next;
				delete BeDel;
				BeDel = NULL;
				BeDel = next;
			}

			if(PreNode == NULL)//说明删除的是头结点
			{
				*head = next;
			}
			else
			{
				PreNode->_next = next;
			}

			cur = next;
		}
	}
}

void Print(Node* root)
{
	Node* cur = root;
	while(cur != NULL)
	{
		cout<<cur->_value<<" ";
		cur = cur->_next;
	}
	cout<<endl;
}

void TestDelete()
{
	Node* root = new Node(1);
	PushBack(&root,1);
	PushBack(&root,2);
	PushBack(&root,3);
	PushBack(&root,3);
	PushBack(&root,3);
	PushBack(&root,4);
	PushBack(&root,4);
	PushBack(&root,5);

	DeleteDuplication(&root);
	Print(root);
}

int main()
{
	TestDelete();
	system("pause");
	return 0;
}