#pragma once

#include <iostream>
#include <assert.h>
using namespace std;

void SelectSort(int* a,size_t n)
{
	assert(a);
	size_t begin = 0;
	size_t end = n-1;

	while(begin < end)
	{
		size_t min = begin, max = end;
		for(size_t i=begin; i<=end; i++)
		{
			//ѡ���ֵ����Сֵ���±�
			if(a[i] < a[min])
			{
				min = i;
			}

			if(a[i] > a[max])
			{
				max = i;
			}
		}
		//���� 
		if(max == begin) //����max==beginʱ��Ӧ�������⴦��
		{
			max = min;
		}
		swap(a[begin],a[min]);
		swap(a[end],a[max]);

		++begin;
		--end;
	}
}

void TestSelectSort()
{
	int a[] = {10,5,4,9,3,6,8,7,1};
	size_t len = sizeof(a)/sizeof(a[0]);

	SelectSort(a,len);

	for(size_t i=0; i<len; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}