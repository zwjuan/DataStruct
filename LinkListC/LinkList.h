#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


typedef int DataType;//������char�����޸ģ���ά���Դ��룩

typedef struct Node
{
	DataType data;
	struct Node* next;
}Node;


void PushBack(Node** pphead, DataType x);//ppheadӦΪ����ָ��
void PopBack(Node** pphead);
void PushFront(Node** pphead, DataType x);
void PopFront(Node** pphead);
Node* Find(Node* phead,DataType x);
void PrintList(Node* phead);

#endif __LINKLIST_H__