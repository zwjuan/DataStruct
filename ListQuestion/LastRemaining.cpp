
/*
	0,1,...,n-1这n个数字排成一个圆圈，从数字0开始每次从这个圆圈里删除第m个数字。
	求出这个圆圈里剩下的最后一个数字。

	解法：1.经典解法，用环形链表模拟圆圈
			分析：这种方法每删除一个数字 需要m步运算，总共有n个数字，时间复杂度为O(mn),
				  还需要一个辅助链表来模拟圆圈，空间复杂度是O(n).
		  2.分析每次被删除的数字的规律并直接计算出圆圈中最后剩下的数字。
			分析：f(n,m) = 0 //n = 1;  f(n,m) = [f(n-1,m)+m]%n n>1  (循环或递归求解)
				这种算法的时间复杂度为O(n),空间复杂度为O(1).
*/

#include <iostream>
#include<list>  //用list模拟环形链表
using namespace std;

//
//n个结点的环形链表，每次在这个链表中删除第m个结点
int LastRemaining(unsigned int n, unsigned int m)
{
	if(n < 1 || m < 1)
	{
		return -1;
	}

	//构建n个结点的链表
	list<int> numbers;
	for(unsigned int i=0; i<n; i++)
	{
		numbers.push_back(i);
	}

	//利用迭代器遍历删除结点（若迭代器到达链表的尾端，则调整到开头）
	list<int>::iterator it = numbers.begin();
	while(numbers.size() != 1)
	{
		unsigned int i = 1;//应从1开始
		for(;i<m;i++)
		{
			it++;	
			if(it == numbers.end())
			{
				it = numbers.begin();
			}
		}
		
		list<int>::iterator next = ++it;
		if(next == numbers.end())
		{
			next = numbers.begin();
		}

		--it;
		numbers.erase(it);
		it = next;
	
	}
	return *it;
}

int LastRemainingR(unsigned int n, unsigned int m)
{
	if(n < 1 || m < 1)
		return -1;

	int last = 0;
	for(int i=2; i<=n; i++)
	{
		last = (last + m)%i;
	}
	return last;
}

void TestLastRemaining()
{
	//性能测试：从最初有4000个数字的圆圈中每次删除第997个数字
	cout<<LastRemaining(4000,997)<<endl;
}


int main()
{
	TestLastRemaining();
	system("pause");
	return 0;
}


