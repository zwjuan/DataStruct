#include<iostream>
using namespace std;
/*
��Ŀ����������ĸ���
�ڸ��������У�ÿ���ڵ������һ��m_pNextָ��ָ����һ������⣬����һ��m_pSiblingָ�������е��������NULL��
������1.����ÿ����㣬�����ӵ����ĺ���
	  2.��m_pSibling
	  3.���ԭ�����븴������
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

//���ƽ��
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
//��SibkingNodes���
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
//���
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