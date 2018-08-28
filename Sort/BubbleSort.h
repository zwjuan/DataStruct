#pragma once

#include <iostream>
#include <assert.h>
using namespace std;

void BubbleSort(int* a, size_t n)
{
	assert(n);
	bool finish = false; //����������Ż�
	size_t end = n;
	while(end > 0) //end��ʾÿ��ð�ݵ���ֹλ��
	{
		//����ð��
		for(size_t i=1; i<end; i++)
		{
			if(a[i-1]>a[i])
			{
				swap(a[i-1],a[i]);
				finish = true;  //���������������ݽ�������finish��Ϊtrue
			}
		}

		if(finish == false)  //�жϵ����������Ƿ��н���
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