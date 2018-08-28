#pragma once

#include <iostream>
#include <assert.h>
using namespace std;

//插入排序---升序（从后向前查找插入位置）
void InsertSort(int* a,  size_t n)
{
	assert(a);

	for(size_t i=1; i<n; ++i)
	{
		int end = i-1;
		int tmp = a[i];
		while(a[end] > tmp && end >= 0) //挪动数据
		{
			a[end+1] = a[end];
			--end;
		}
		a[++end] = tmp; //插入数据
	}
}

//插入排序优化（利用二分查找寻找插入的位置）
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

	if(a[mid] <= data) //返回数据要插入的数据
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

		if(index != i) //当插入位置不为i时，才挪动数据进行插入
		{
			int j=i;
			int tmp = a[i];
			while(j > index) //挪动数据
			{
				a[j] = a[j-1];
				--j;
			}
			a[index] = tmp;//插入
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

