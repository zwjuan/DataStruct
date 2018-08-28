#pragma once

#include<iostream>
using namespace std;
void CountSort(int* a, int n)
{
	//ͳ�����������С�����㿪�ռ�
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

	//ʹ��ֱ�ӵ�ַ��
	int range = max - min - 1;
	int* hashtable = new int[range]; //new�������費��Ҫ���г�ʼ��

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