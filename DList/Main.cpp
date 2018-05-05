#include"DList.h"

void TestList()
{
	List List;
	List.PushBack (1);
	List.PushBack (2);
	List.PushBack (3);

	List.Print ();

	List.Reverse ();
	List.Print ();
	List.Insert (List.Find(3),3);
	List.Erase (List.Find(3));
	List.Erase (List.Find(3));

	List.Print ();
}

int main()
{
	TestList();
	system("pause");
	return 0;
}