#include"list_contiguous.h"
#include<iostream>
using namespace std;

template<class List_entry>
bool List<List_entry>::empty()const		//�Ƿ��
{
	return count == 0;
}

template<class List_entry>
int List<List_entry>::size()const		//��ǰ��С
{
	return count;
}

template<class List_entry>				//�Ƿ���
bool List<List_entry>::full()const
{
	return count == max_size;
}

template<class List_entry>				//����ָ�����
void List<List_entry>::traverse(void(*visit)(List_entry&))
{
	for (int i = 0; i < count; i++) (*visit)(entry[i]);
}

template<class List_entry>				//ȡ��ֵ
Error_code List<List_entry>::retrieve(int position, List_entry& x)const
{
	if (position < 0 || position >= count)return Range_error;
	x = entry[position];
	return success;
}

template<class List_entry>				//�Ƴ�
Error_code List<List_entry>::remove(int position, List_entry& x)
{
	if (empty())return underflow;
	if (position < 0 || position >= count)return Range_error;
	x = entry[position];				//��¼ԭ��λ��ֵ
	for (int i = position; i <= count - 1; i++)
		entry[i] = entry[i + 1];
	count--;
	return success;
}

template<class List_entry>				//����
Error_code List<List_entry>::insert(int	position, const List_entry& x)
{
	if (full())return overflow;
	if (position <0 || position>count)return Range_error;
	for (int i = count - 1; i >= position; i--)
		entry[i + 1] = entry[i];
	entry[position] = x;
	count++;
	return success;
}