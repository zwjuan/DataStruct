#include "LinkList.h"

//PushBack(),PopBack()
void TestList()
{
	Node* List = NULL;//����ΪNULL,��һ��ָ����ΪNULLָ��
	PushBack (&List,1);
	PushBack (&List,2);
	PushBack (&List,3);
    PrintList (List);//1 2 3

    PopBack(&List);
    PopBack(&List);
    PopBack(&List);
    PopBack(&List);

    PrintList (List);

} 

int main()
{
	TestList();
	system("pause");
	return 0;
}