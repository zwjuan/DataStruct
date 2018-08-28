#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

void _MergeSort(int* a, int left, int right, int* tmp)//tmpΪ��ʱ�ռ�
{
	if(left >= right) //���ж������Ƿ���Ч
	{
		return ; 
	}

	int mid = left+((right-left)>>1);
	//[left,mid] [mid+1,right]
	
	_MergeSort(a,left,mid,tmp);
	_MergeSort(a,mid+1,right,tmp);


	//�鲢
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

	//����begin1��begin2����Ԫ��
	while(begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}

	while(begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}

	//����ԭ����
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
	delete[] tmp; //���ٿռ䲻Ҫ�����ͷ�
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