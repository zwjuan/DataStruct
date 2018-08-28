#pragma once

#include <iostream>
#include <assert.h>
#include <windows.h>
#include <time.h>
#include <stack>
#include "InsertSort.h"
using namespace std;

//����ָ�뷨	��һ��key,���������ƣ�С�����ƣ�����������仮��Ϊ������ [] key []
int PartSort1(int* a, int begin, int end)
{
	int left = begin, right = end; //right��ֵΪ end ���� end-1
	int key = a[right]; //ѡ�����ұ�Ϊkeyֵ
	//��������
	while(begin < end)
	{
		//begin�Ҵ���
		while(begin < end && a[begin] <= key) //ע������a[begin] <= key 
		{
			++begin;
		}

		//end��С
		while(begin < end && a[end] >= key)
		{
			--end;
		}

		swap(a[begin], a[end]);
	}
	swap(a[begin],a[right]); //a[right]�൱���м仮�ֵ�λ��

	return begin; //����ֵ�������
}

//�ڿӷ�(�ҵ�һ���ӣ�����һ���ұ�������������䣬�ӵ�λ�øı䣬�ڴ���һ���ұ���С����)	
int PartSort2(int* a, int begin, int end)
{
	int key = a[end];
	while(begin < end)
	{
		while(begin<end && a[begin] <= key)
		{
			++begin;
		}

		a[end] = a[begin];

		while(begin < end && a[end] >= key)
		{
			--end;
		}
		a[begin] = a[end];
	}
	a[begin] = key;

	return begin;	
}

//ǰ��ָ�뷨 ������prev �� cur �� (****�㷨�ĺܺ��Ż�)
int PartSort3(int* a, int begin, int end)
{
	int key = a[end];
	int cur = begin, prev = cur-1; //cur=begin ,����Ϊ0����Ϊ���䲻�ܲ�һ����0��ʼ

	while(cur < end)
	{
		if(a[cur] < key && ++prev != cur)
		{
			swap(a[prev], a[cur]);
		}
		++cur;
	}
	swap(a[++prev],a[end]);
	return prev;
}

//����ȡ�з�(����ֵ���м������ֵ�������м���ֵ��С��)������
int GetMidIndex(int* a, int begin, int end)
{
	int mid = begin + ((end-begin)>>1);
	//ѡ�����������м�ֵ
	if(a[begin] > a[mid])
	{
		if(a[mid]>a[end])//begin>mid>and
		{
			return mid;
		}
		else if(a[begin] > a[end])//begin>mid,mid<end,begin>end
		{
			return end;
		}
		else
		{
			return begin;
		}
	}
	else //mid>begin
	{
		if(a[end]>a[mid])
		{
			return mid;
		}
		else if(a[end]>a[begin])
		{
			return end;
		}
		else
		{
			return begin;
		}
	}
}

//ʹ������ȡ�з�
int PartSort1PMid(int* a, int begin, int end)
{
	int left = begin, right = end; //right��ֵΪ end ���� end-1
	
	int mid = GetMidIndex(a,begin,end); //����ȡ�з�
	swap(a[right],a[mid]);//�����м����ұߵ���
	
	int key = a[right]; //ѡ�����ұ�Ϊkeyֵ

	//��������
	while(begin < end)
	{
		//begin�Ҵ���
		while(begin < end && a[begin] <= key) //ע������a[begin] <= key 
		{
			++begin;
		}

		//end��С
		while(begin < end && a[end] >= key)
		{
			--end;
		}

		swap(a[begin], a[end]);
	}
	swap(a[begin],a[right]); //a[right]�൱���м仮�ֵ�λ��

	return begin; 
}

//�Ż������ٵݹ���������ݹ鵽С����ʱ��ʹ�ò�������
int PartSort1P(int* a, int begin, int end)
{
	int left = begin, right = end; //right��ֵΪ end ���� end-1
	int mid = GetMidIndex(a,begin,end); //����ȡ�з�
	swap(a[right],a[mid]);//�����м�������

	int key = a[right]; //ѡ�����ұ�Ϊkeyֵ

	//��������
	while(begin < end)
	{
		//begin�Ҵ���
		while(begin < end && a[begin] <= key) //ע������a[begin] <= key 
		{
			++begin;
		}

		//end��С
		while(begin < end && a[end] >= key)
		{
			--end;
		}

		swap(a[begin], a[end]);
	}
	swap(a[begin],a[right]); //a[right]�൱���м仮�ֵ�λ��

	return begin; //����ֵ�������
}
void QuickSortP(int* a, int left, int right)
{
	assert(a);

	//���ŵ��Ż������ݹ鵽С����ʱ��ʹ�ò�������
	if(right - left + 1 <10) //ע�⣺�����������ж�
	{
		InsertSort(a+left,right-left+1);
		return;
	}
	else
	{
		int div = PartSort1(a, left, right);

		QuickSortP(a, left,div-1);
		QuickSortP(a, div+1, right);
	}
	
}

//�ǵݹ�ʵ�֣���·�ݹ飬����ջ��
//˼·��ջ�б��������±꣬��ѹ�ҡ���ѹ��ջ��Ϊ��ȡ����ջΪ��ʱѭ������
void QuickSortFD(int* a, int left, int right)
{
	stack<int> s; //ջ�д���±�
	if(left < right) //����Ҫ��֤�±���������ѹջ
	{
		s.push(right);
		s.push(left);
	}

	while(s.size()>0)
	{
		
		int left = s.top();
		s.pop();
		int right = s.top();
		s.pop();
		if(right - left <= 20)
		{
			InsertSort(a+left,right-left+1);
			return;
		}
		else
		{
			int div = PartSort1(a,left,right);

			if(div - 1 >left) //���䲻�Ϸ�ʱ������ջ
			{
				s.push(div-1);
				s.push(left);
			}

			if(right > div+1)
			{
				s.push(right);
				s.push(left);
			}
		}
	}
}


//��ͨ����
void QuickSort(int* a, int left, int right)
{
	assert(a);

	if(left >= right) //ע�⣺�����������ж�
	{
		return;
	}

	int div = PartSort1(a, left, right);

	QuickSort(a, left,div-1);
	QuickSort(a, div+1, right); //rightΪʲô��-1��
}


//[begin,end]�� begin end ��Ϊ������
//�������з�����
void QuickSortPMid(int* a, int left, int right)
{
	assert(a);

	if(left >= right) //ע�⣺�����������ж�
	{
		return;
	}

	int div = PartSort1PMid(a, left, right);

	QuickSortPMid(a, left,div-1);
	QuickSortPMid(a, div+1, right);
}

void TestQuickSort()
{
	//srand((unsigned)time(NULL));

	//int a[10000]; 
	//for(size_t i=0; i<10000;i++)
	//{
	//	a[i] = rand()%20000;
	//}
	int a[] = {2,0,4,9,3,6,8,7,1,5};
	int len = sizeof(a)/sizeof(a[0]);
	QuickSortFD(a,0,len-1);

	//��ͨ����
	/*int start = GetTickCount();
	QuickSort(a,0,len-1);
	int end = GetTickCount();
	cout<<"end-start: "<<end-start<<endl;*/

	for(size_t i=0; i<len; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;

	////�Ż�����
	/*int startP = GetTickCount();
	QuickSortPMid(a,0,len-1);
	int endP = GetTickCount();
	cout<<"endP-startP: "<<endP-startP<<endl;

	for(size_t i=0; i<len; i++)
	{
	cout<<a[i]<<" ";
	}
	cout<<endl;*/
	
}