#include"DList.h"

void TestList()
{
	List<int> List1;
	List1.PushFront (1);
	List1.PushFront (2);
	List1.PushFront (3);
	List1.PushFront (4);
	List1.PushFront (5);
	List1.PopFront ();
	ListNode<int>* pos = List1.Find(333);
	List1.Insert (pos,10);
	List1.Erase (pos);

	List1.Print ();
}

int main()
{
	TestList();

	system("pause ");
	return 0;
}
