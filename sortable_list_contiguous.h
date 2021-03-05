#pragma once

#include"list_contiguous.h"
#include"list_contiguous.cpp"

template <class List_entry>		//�������
class Sortable_list :public List<List_entry>
{
public:
	Sortable_list<List_entry>(int List_size = 0) : List<List_entry>(List_size) {}
	void selection_sort();
	void shell_sort();
	void quick_sort_1();

private:
	int max_key(int low, int high);
	void Swap(int low, int high);
	void sort_interval(int start, int increment);
	void recursive_quick_sort_1(int low, int high);
	int partition(int low, int high);
	int median(int a, int b, int c);
};