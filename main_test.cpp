#include"sortable_list_contiguous.h"
#include"sortable_list_contiguous.cpp"
void print(int& entry)
{
	cout << entry;
}

int main()
{
	Sortable_list<int> s(8);
	s.insert(0, 2); s.insert(0, 1); s.insert(0, 7);
	s.insert(0, 4); s.insert(0, 9); s.insert(0, -2);
	s.insert(0, 0); s.insert(0, 4);
	s.traverse(print);
	cout << endl;
	s.quick_sort_1();
	s.traverse(print);
}