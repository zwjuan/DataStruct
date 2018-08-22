#pragma once

#include <iostream>
#include <assert.h>
using namespace std;

void ShellSort(int* a, size_t n)
{
	assert(a);

	int gap = n;//表示每隔gap个数据分一组
	while(gap > 1)
	{
		gap = gap/3 + 1;
		for(size_t i=gap; i<n; i++)
		{
			int end = i-gap;
			int tmp = a[end+gap];
			while(a[end] > tmp && end >= 0)
			{
				a[end+gap] = a[end];
				end -= gap;
			}
			a[end+gap] = tmp;
		}
	}
}

void TestShellSort()
{
	int a[] = {2,5,4,3,6,8,7,1,0};
	size_t len = sizeof(a)/sizeof(a[0]);

	ShellSort(a,len);
	for(size_t i=0; i<len; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}