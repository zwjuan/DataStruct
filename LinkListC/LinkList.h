#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


typedef int DataType;//若插入char方便修改（可维护性代码）

typedef struct Node
{
	DataType data;
	struct Node* next;
}Node;


void PushBack(Node** pphead, DataType x);//pphead应为二级指针
void PopBack(Node** pphead);
void PushFront(Node** pphead, DataType x);
void PopFront(Node** pphead);
Node* Find(Node* phead,DataType x);
void PrintList(Node* phead);

#endif __LINKLIST_H__