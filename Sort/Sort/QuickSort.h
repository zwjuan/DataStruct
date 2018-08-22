#pragma once

#include <iostream>
#include <assert.h>
#include <windows.h>
#include <time.h>
#include <stack>
#include "InsertSort.h"
using namespace std;

//左右指针法	找一个key,将大数右移，小数左移，最后将数组区间划分为两部分 [] key []
int PartSort1(int* a, int begin, int end)
{
	int left = begin, right = end; //right赋值为 end 还是 end-1
	int key = a[right]; //选择最右边为key值
	//单趟排序
	while(begin < end)
	{
		//begin找大于
		while(begin < end && a[begin] <= key) //注意条件a[begin] <= key 
		{
			++begin;
		}

		//end找小
		while(begin < end && a[end] >= key)
		{
			--end;
		}

		swap(a[begin], a[end]);
	}
	swap(a[begin],a[right]); //a[right]相当于中间划分的位置

	return begin; //返回值情况？？
}

//挖坑法(找到一个坑，从另一端找比它大数的数填充，坑的位置改变，在从另一端找比它小的数)	
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

//前后指针法 （定义prev 和 cur ） (****算法的很好优化)
int PartSort3(int* a, int begin, int end)
{
	int key = a[end];
	int cur = begin, prev = cur-1; //cur=begin ,不能为0，因为区间不能不一定从0开始

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

//三数取中法(返回值是中间这个数值，还是中间数值的小标)？？？
int GetMidIndex(int* a, int begin, int end)
{
	int mid = begin + ((end-begin)>>1);
	//选择三个数的中间值
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

//使用三数取中法
int PartSort1PMid(int* a, int begin, int end)
{
	int left = begin, right = end; //right赋值为 end 还是 end-1
	
	int mid = GetMidIndex(a,begin,end); //三数取中法
	swap(a[right],a[mid]);//交换中间与右边的数
	
	int key = a[right]; //选择最右边为key值

	//单趟排序
	while(begin < end)
	{
		//begin找大于
		while(begin < end && a[begin] <= key) //注意条件a[begin] <= key 
		{
			++begin;
		}

		//end找小
		while(begin < end && a[end] >= key)
		{
			--end;
		}

		swap(a[begin], a[end]);
	}
	swap(a[begin],a[right]); //a[right]相当于中间划分的位置

	return begin; 
}

//优化：减少递归次数（当递归到小区间时，使用插入排序）
int PartSort1P(int* a, int begin, int end)
{
	int left = begin, right = end; //right赋值为 end 还是 end-1
	int mid = GetMidIndex(a,begin,end); //三数取中法
	swap(a[right],a[mid]);//交换中间两个数

	int key = a[right]; //选择最右边为key值

	//单趟排序
	while(begin < end)
	{
		//begin找大于
		while(begin < end && a[begin] <= key) //注意条件a[begin] <= key 
		{
			++begin;
		}

		//end找小
		while(begin < end && a[end] >= key)
		{
			--end;
		}

		swap(a[begin], a[end]);
	}
	swap(a[begin],a[right]); //a[right]相当于中间划分的位置

	return begin; //返回值情况？？
}
void QuickSortP(int* a, int left, int right)
{
	assert(a);

	//快排的优化（当递归到小区间时，使用插入排序）
	if(right - left + 1 <10) //注意：结束条件的判断
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

//非递归实现（多路递归，借助栈）
//思路：栈中保存左右下标，先压右、再压左，栈不为空取出，栈为空时循环结束
void QuickSortFD(int* a, int left, int right)
{
	stack<int> s; //栈中存放下标
	if(left < right) //首先要保证下标有意义再压栈
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

			if(div - 1 >left) //区间不合法时，不入栈
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


//普通快排
void QuickSort(int* a, int left, int right)
{
	assert(a);

	if(left >= right) //注意：结束条件的判断
	{
		return;
	}

	int div = PartSort1(a, left, right);

	QuickSort(a, left,div-1);
	QuickSort(a, div+1, right); //right为什么不-1；
}


//[begin,end]， begin end 均为闭区间
//三数区中法排序
void QuickSortPMid(int* a, int left, int right)
{
	assert(a);

	if(left >= right) //注意：结束条件的判断
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

	//普通快排
	/*int start = GetTickCount();
	QuickSort(a,0,len-1);
	int end = GetTickCount();
	cout<<"end-start: "<<end-start<<endl;*/

	for(size_t i=0; i<len; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;

	////优化快排
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