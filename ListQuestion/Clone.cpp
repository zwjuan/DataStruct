#include<iostream>
using namespace std;
/*
题目：复杂链表的复制
在复杂链表中，每个节点除了有一个m_pNext指针指向下一个结点外，还有一个m_pSibling指向链表中的任意结点或NULL。
方法：1.复制每个结点，并连接到它的后面
	  2.置m_pSibling
	  3.拆分原链表与复杂链表
*/
typedef struct ComplexListNode
{
	int m_nValue;
	ComplexListNode* m_pNext;
	ComplexListNode* m_pSibling;

	ComplexListNode(const int& v)
		:m_nValue(v)
		,m_pNext(NULL)
		,m_pSibling(NULL)
	{}
}Node;

//复制结点
void CloneNodes(Node* pHead)
{
	Node* pNode = pHead;
	while(pNode != NULL)
	{
		Node* newNode = new Node(pNode->m_nValue);
		newNode->m_pNext = pNode->m_pNext;
		pNode->m_pNext = newNode;

		pNode = newNode->m_pNext;
	}
}
//置SibkingNodes结点
void ConnectSiblingNodes(Node* pHead)
{
	Node* pNode = pHead;
	while(pNode != NULL)
	{
		Node* Sibling = pNode->m_pSibling;
		Node* newNode = pNode->m_pNext;
		if(Sibling != NULL)
		{
			newNode->m_pSibling = Sibling->m_pNext;
		}

		pNode = newNode->m_pNext;
	}
}
//拆分
Node* ReconnectNodes(Node* pHead)
{
	Node *pNode = pHead;
	Node *newHead = NULL;
	Node *newNode = NULL;

	if(pNode != NULL)
	{
		newHead = pNode->m_pNext;
		newNode = newHead;

		pNode ->m_pNext = newNode->m_pNext;
		pNode = newNode->m_pNext;
	}

	while(pNode != NULL)
	{
		newNode->m_pNext = pNode->m_pNext;
		newNode = pNode->m_pNext;
		
		pNode->m_pNext = newNode->m_pNext;
		pNode = newNode->m_pNext;
	}
	return newHead;
}

Node* Clone(Node* pHead)
{
	if(pHead == NULL)
	{
		return NULL;
	}
	Node* newHead = NULL;
	CloneNodes(pHead);
	ConnectSiblingNodes(pHead);
	return ReconnectNodes(pHead);
	
}

void Print(Node* phead)
{
	while(phead != NULL)
	{
		cout<<"phead->m_nValue:"<<phead->m_nValue<<" ";
		if(phead->m_pSibling != NULL)
		{
			cout<<"phead->m_pSibling->m_nValue: "<<phead->m_pSibling->m_nValue<<endl;
		}
		else
		{
			cout<<"phead->m_pSibling->m_nValue:  NULL"<<endl;
		}

		phead = phead->m_pNext;
	}
}

void TestClone()
{
	Node* node1 = new Node(1);
	Node* node2 = new Node(2);
	Node* node3 = new Node(3);
	Node* node4 = new Node(4);
	Node* node5 = new Node(5);

	node1->m_pNext = node2;
	node1->m_pSibling = node3;
	node2->m_pNext = node3;
	node2->m_pSibling = node5;
	node3->m_pNext = node4;
	node4->m_pNext = node5;
	node4->m_pSibling = node2;
	Print(node1);
	cout<<endl;
	Print(Clone(node1));
}

int main()
{
	TestClone();
	system("pause");
	return 0;
}