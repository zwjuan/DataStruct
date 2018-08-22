#pragma once

#include<iostream>
using namespace std;
void CountSort(int* a, int n)
{
	//统计最大数，最小数方便开空间
	int max = a[0],min = a[0];
	for(int i=0; i<n; i++)
	{
		if(a[i]>max)
		{
			max = a[i];
		}

		if(a[i]<min)
		{
			min = a[i];
		}
	}

	//使用直接地址法
	int range = max - min - 1;
	int* hashtable = new int[range]; //new的数组需不需要进行初始化

	for(size_t i=0; i<n; i++)
	{
		hashtable[a[i]-min]++;
	}

	size_t j=0;
	for(size_t i=0; i<range; i++)
	{
		while(hashtable[i]--)
		{
			a[j] = i+min;
			++j;
		}
	}

	delete[] hashtable;

}