/*
	链表中环的入口结点
	题目：一个链表的包含环，如何找出环的入口结点
*/

#include "iostream"
using namespace std;

typedef int DataType;

typedef struct ListNode
{
	DataType _value;
	struct ListNode* _next;

	ListNode(const int& x)
		:_value(x)
		,_next(NULL)
	{}
}Node;

//判断链表是否带环（利用快慢指针判断链表是否带环）
Node* IsCycle(Node* root)
{
	Node* slow = root;
	Node* fast = root;
	while(fast && fast->_next)
	{
		slow = slow->_next;
		fast = fast->_next->_next;
		if(fast == slow)
		{
			return fast;
		}
	}
	return false; 
}

Node* EntryNode(Node* root)
{
	if(root == NULL)
	{
		return false;
	}

	//先判断链表是否带环
	Node* meet = IsCycle(root); //meetNode为相遇结点
	if(meet == false)
	{
		return NULL;	
	}

	//相遇点到环入口结点与头结点到环入口结点的距离相等
	Node* cur = root;
	while(cur != meet)
	{
		cur = cur->_next;
		meet = meet->_next;
	}
	return cur; 
}

//求环的长度
int LengthClycle(Node* root)
{
	Node* meet = IsCycle(root);
	if(meet == NULL)
	{
		return 0;
	}

	Node* cur = meet->_next;
	int len = 1;
	while(cur != meet)
	{
		++len;
		cur =  cur->_next;
	}
	return len;
}

void TestMeetingNode()
{
	Node* node1 = new Node(1);
	Node* node2 = new Node(2);
	Node* node3 = new Node(3);
	Node* node4 = new Node(4);
	Node* node5 = new Node(5);

	node1->_next = node2;
	node2->_next = node3;
	node3->_next = node4;
	node4->_next = node5;
	node5->_next = node3;
	//node1->_next = node1;
	Node* entry = EntryNode(node1);
	cout<<"环的长度为："<<LengthClycle(node1)<<endl;
	if(entry != false)
	{
		cout<<entry->_value<<endl;
	}
}

int main()
{
	TestMeetingNode();

	system("pause");
	return 0;
}