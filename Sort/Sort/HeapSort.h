#pragma once

#include <iostream>
#include <assert.h>
using namespace std;

//������ʱ�临�Ӷ�ΪO��nlogN����
void AdjustDown(int* a, size_t n, int root) //���µ����㷨
{
	int parent = root;
	int child = parent*2+1;
	while(child < n)
	{
		if(child+1<n && a[child] < a[child+1]) //����������ʱ�������ж�   
		{
			++child;
		}

		if(a[child] > a[parent])
		{
			swap(a[parent],a[child]);
			parent = child;
			child = parent*2;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int *a, size_t n)
{
	assert(a);

	//����ѣ���һ��Ԫ��Ϊ���ֵ��
	for(int i=(n-1-1)/2; i>=0; --i)
	{
		AdjustDown(a,n,i); 
	}
	//���򣨽���һ��Ԫ�������һ��Ԫ�ؽ��н������ٽ������µ����㷨��
	int len = n-1;
	while(len > 0)
	{
		swap(a[0],a[len]);
		AdjustDown(a,--len,0);
	/*	len--;*/
	}
}

void TestHeapSort()
{
	int a[] = {2,5,4,3,6,8,7,1,0};
	int len = sizeof(a)/sizeof(a[0]);

	HeapSort(a,len);

	for(size_t i=0; i<len; i++)
	{
		cout<<a[i]<<" ";
	}

	cout<<endl;
}