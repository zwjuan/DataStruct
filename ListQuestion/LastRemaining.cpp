
/*
	0,1,...,n-1��n�������ų�һ��ԲȦ��������0��ʼÿ�δ����ԲȦ��ɾ����m�����֡�
	������ԲȦ��ʣ�µ����һ�����֡�

	�ⷨ��1.����ⷨ���û�������ģ��ԲȦ
			���������ַ���ÿɾ��һ������ ��Ҫm�����㣬�ܹ���n�����֣�ʱ�临�Ӷ�ΪO(mn),
				  ����Ҫһ������������ģ��ԲȦ���ռ临�Ӷ���O(n).
		  2.����ÿ�α�ɾ�������ֵĹ��ɲ�ֱ�Ӽ����ԲȦ�����ʣ�µ����֡�
			������f(n,m) = 0 //n = 1;  f(n,m) = [f(n-1,m)+m]%n n>1  (ѭ����ݹ����)
				�����㷨��ʱ�临�Ӷ�ΪO(n),�ռ临�Ӷ�ΪO(1).
*/

#include <iostream>
#include<list>  //��listģ�⻷������
using namespace std;

//
//n�����Ļ�������ÿ�������������ɾ����m�����
int LastRemaining(unsigned int n, unsigned int m)
{
	if(n < 1 || m < 1)
	{
		return -1;
	}

	//����n����������
	list<int> numbers;
	for(unsigned int i=0; i<n; i++)
	{
		numbers.push_back(i);
	}

	//���õ���������ɾ����㣨�����������������β�ˣ����������ͷ��
	list<int>::iterator it = numbers.begin();
	while(numbers.size() != 1)
	{
		unsigned int i = 1;//Ӧ��1��ʼ
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
	//���ܲ��ԣ��������4000�����ֵ�ԲȦ��ÿ��ɾ����997������
	cout<<LastRemaining(4000,997)<<endl;
}


int main()
{
	TestLastRemaining();
	system("pause");
	return 0;
}


