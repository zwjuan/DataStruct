#pragma once

#include <iostream>
#include <assert.h>
using namespace std;

void BubbleSort(int* a, size_t n)
{
	assert(n);
	bool finish = false; //堆排序进行优化
	size_t end = n;
	while(end > 0) //end表示每次冒泡的终止位置
	{
		//单趟冒泡
		for(size_t i=1; i<end; i++)
		{
			if(a[i-1]>a[i])
			{
				swap(a[i-1],a[i]);
				finish = true;  //若单趟排序有数据交换，则将finish置为true
			}
		}

		if(finish == false)  //判断单趟排序中是否有交换
		{
			return;
		}

		--end;
	}
}

void TestBubbleSort()
{
	int a[] = {2,5,4,9,3,6,8,7,1};
	size_t len = sizeof(a)/sizeof(a[0]);

	BubbleSort(a,len);

	for(size_t i=0; i<len; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}