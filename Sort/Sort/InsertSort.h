#pragma once

#include <iostream>
#include <assert.h>
using namespace std;

//��������---���򣨴Ӻ���ǰ���Ҳ���λ�ã�
void InsertSort(int* a,  size_t n)
{
	assert(a);

	for(size_t i=1; i<n; ++i)
	{
		int end = i-1;
		int tmp = a[i];
		while(a[end] > tmp && end >= 0) //Ų������
		{
			a[end+1] = a[end];
			--end;
		}
		a[++end] = tmp; //��������
	}
}

//���������Ż������ö��ֲ���Ѱ�Ҳ����λ�ã�
int BinaryFindIndex(int* a, size_t n, int data)
{
	int start = 0;
	int end = n-1;
	int mid = 0;
	while(start <= end)
	{
		mid = start+((end - start)>>1);
		
		if(a[mid] < data)
		{
			start = mid+1;
		}
		else
		{
			end = mid-1;
		}

	}

	if(a[mid] <= data) //��������Ҫ���������
	{
		mid++;
	}

	return mid;
}

void InsertSortP(int* a, size_t n)
{
	assert(a);

	for(size_t i=1; i<n; i++)
	{
		int index =  BinaryFindIndex(a,i,a[i]);

		if(index != i) //������λ�ò�Ϊiʱ����Ų�����ݽ��в���
		{
			int j=i;
			int tmp = a[i];
			while(j > index) //Ų������
			{
				a[j] = a[j-1];
				--j;
			}
			a[index] = tmp;//����
		}
	}
}


void TestInsertSort()
{
	int a[] = {2,5,4,3,6,8,7,1,0};
	int len = sizeof(a)/sizeof(a[0]);

	InsertSort(a,len);
	for(size_t i=0; i<len; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void TestBinaryFind()
{
	int a[] = {2,5,4,3,6,8,7,1,0};
	int len = sizeof(a)/sizeof(a[0]);

	InsertSortP(a,len);

	for(size_t i=0; i<len; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

