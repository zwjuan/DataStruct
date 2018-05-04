#include"LinkList.h"

void TestList()
{
	SList SList;
	

	SList.PushBack(13);
	SList.PushBack(18);

	//SList.PopBack();
	SList.Print();

}

int main()
{
	TestList1();
	system("pause");
	return 0;
}