#include"LinkList.h"

Node* BuyNode(DataType x)
{
    Node* node = (Node* )malloc(sizeof(Node));
	node->data  = x;
	node->next = NULL;
	return node;
}

void PrintList(Node* phead)
{
	Node* cur = phead;
	if(phead == NULL)
	{
		printf("此链表为空链表\n");
	}
	while(cur!=NULL)
	{
		printf("%d ",cur->data );
		cur = cur->next;
	}
	printf("\n");
}

//pphead应为二级指针，当向一个空链表插入一个结点时，新插入的结点就是链表的头指针。
//由于此处会改动头指针，因此必须把pphead设置为二级指针，否则phead为值传递，出了这个作用域phead仍然是一个空指针
void PushBack(Node** pphead, DataType x)
{
	if(*pphead == NULL)
	{
		*pphead = BuyNode (x);
	}
	else
	{
		Node* tail = *pphead;
		while(tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = BuyNode (x);
	}
}

void PopBack(Node** pphead)
{
	if(*pphead == NULL)//空链表
	{
		return;//若为空链表直接返回
	}
	else
	{
		if((*pphead)->next == NULL)//只有一个节点
		{
			free(*pphead);
			*pphead = NULL;
		}
		//大于一个节点
		else
		{
			Node* cur = *pphead;//当前节点的前一个节点
			Node* prev = NULL;//当前节点
			while(cur->next)
			{
				prev = cur;
				cur = cur->next ;
			}
			free(cur);
			prev->next = NULL;
		}
	}
}

void PushFront(Node** pphead, DataType x)
{
	if(*pphead == NULL)
	{
		*pphead = BuyNode (x);
	}
	else
	{
		Node* node = BuyNode(x);
		node->next = *pphead;
		*pphead = node;
	}
}

void PopFront(Node** pphead)
{
	if(*pphead == NULL)
	{
		return ;
	}
	else
	{
		if((*pphead)->next == NULL)//???可以不写吗
		{
			free(*pphead);
			*pphead = NULL;
		}
		else
		{
			Node* tmp = *pphead;
			*pphead = (*pphead)->next;
			free(tmp);
			tmp = NULL;
		}
	}
}

Node* Find(Node* phead,DataType x)
{
	Node* cur = phead;
	if(phead == NULL)
	{
		return NULL;
	}
	else
	{
		while(cur)
		{
			if(cur->data == x)
			{
				return cur;
			}
			else
			{
				cur = cur->next ;
			}
		}
		return NULL;
	}
}

void Insert(Node** pphead,Node* pos,DataType x)
{
	assert(pos);
	if(*pphead == pos)//头插
	{
		PushFront(pphead,x);
	}
	else
	{
		Node* prev = *pphead ;
		Node* tmp = BuyNode(x);
		while(prev->next != pos)
		{
			prev = prev->next ;
		} 
		tmp ->next = pos;
		prev->next = tmp;
	}
}

void Erase(Node** pphead,Node* pos)
{
	assert(pos);
	if(*pphead == pos)
	{
		PopFront (pphead);
	}
	else
	{
		Node* cur = *pphead;
		while(cur->next != pos)
		{
			cur = cur->next;
		}
		cur->next = pos->next;
		free(pos);
	}
}