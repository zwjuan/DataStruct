#include"ListC.h"

//求链表长度的函数
size_t GetListLength(Node* phead)
{
	size_t len = 0;
	Node* p = phead;
	while(p != NULL)
	{
		++ len;
		p = p->_next;
	}

	return len;
}

//求两个链表第一个公共结点（1.若两链表相交则尾结点相同）
Node* FindFirstCommonNode(Node* phead1, Node* phead2)
{
	if(phead1 == NULL || phead2 == NULL)
	{
		return NULL;
	}

	//依次遍历两链表，求两链表的长度。 
	size_t len1 = 0;
	size_t len2 = 0;
	len1 = GetListLength(phead1);
	len2 = GetListLength(phead2);

	size_t LenDif = len1 - len2;
	Node* LongHead = phead1;
	Node* ShortHead = phead2;
	
	if(len2 > len1)
	{
		LongHead = phead2;
		ShortHead = phead1;
		LenDif = len2 - len1;
	}

	for(size_t i=0; i<LenDif; i++)
	{
		LongHead = LongHead->_next;
	}

	while(LongHead != ShortHead && LongHead != NULL && ShortHead != NULL)
	{
		LongHead = LongHead->_next;
		ShortHead = ShortHead->_next;
	}

	
	return LongHead;
	
}

void TestFindFirst()
{
	Node* node1 = new Node(10);
	Node* node2 = new Node(3);
	Node* node3 = new Node(14);
	Node* node4 = new Node(17);
	Node* node12 = new Node(20);
	node1->_next = node2;
	node2->_next = node3;
	node3->_next = node4;
	/*node12->_next = node3;*/
	PrintList(node1);
	PrintList(node12);

	Node* com = FindFirstCommonNode(node1,node12);
	if(com != NULL)
	{
		cout<<com->_value<<endl;
	}
}

int main()
{
	TestFindFirst();

	system("pause");
	return 0;
}