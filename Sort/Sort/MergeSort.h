#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

void _MergeSort(int* a, int left, int right, int* tmp)//tmp为临时空间
{
	if(left >= right) //先判断区间是否有效
	{
		return ; 
	}

	int mid = left+((right-left)>>1);
	//[left,mid] [mid+1,right]
	
	_MergeSort(a,left,mid,tmp);
	_MergeSort(a,mid+1,right,tmp);


	//归并
	int index = left;
	int begin1 = left,end1 = mid;
	int begin2 = mid+1,end2 = right;

	while(begin1<=end1 && begin2 <= end2)
	{
		if(a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}

	//拷贝begin1或begin2后面元素
	while(begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}

	while(begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}

	//拷回原数组
	index = left;
	while(index <= right)
	{
		a[index] = tmp[index];
		index++;
	}
}

void MergeSort(int* a, int n)
{
	assert(a);

	int *tmp = new int[n];
	_MergeSort(a,0,n-1,tmp);
	delete[] tmp; //开辟空间不要忘记释放
}

void TestMergeSort()
{
	int a[] = {2,5,4,9,3,6,8,7,1,0};
	//int a[] = {2,0,4,9,3,6,8,7,1,5};
	int len = sizeof(a)/sizeof(a[0]);

	MergeSort(a,len);
	for(size_t i=0; i<len; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;

}