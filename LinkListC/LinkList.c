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
		printf("������Ϊ������\n");
	}
	while(cur!=NULL)
	{
		printf("%d ",cur->data );
		cur = cur->next;
	}
	printf("\n");
}

//ppheadӦΪ����ָ�룬����һ�����������һ�����ʱ���²���Ľ����������ͷָ�롣
//���ڴ˴���Ķ�ͷָ�룬��˱����pphead����Ϊ����ָ�룬����pheadΪֵ���ݣ��������������phead��Ȼ��һ����ָ��
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
	if(*pphead == NULL)//������
	{
		return;//��Ϊ������ֱ�ӷ���
	}
	else
	{
		if((*pphead)->next == NULL)//ֻ��һ���ڵ�
		{
			free(*pphead);
			*pphead = NULL;
		}
		//����һ���ڵ�
		else
		{
			Node* cur = *pphead;//��ǰ�ڵ��ǰһ���ڵ�
			Node* prev = NULL;//��ǰ�ڵ�
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
		if((*pphead)->next == NULL)//???���Բ�д��
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
	if(*pphead == pos)//ͷ��
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