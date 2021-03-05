#include"sortable_list_contiguous.h"

template <class List_entry>		//����λ��
int Sortable_list<List_entry>::max_key(int low, int high)
{
	int largest, current;
	largest = low;
	for (current = low + 1; current <= high; current++)
		if (List<List_entry>::entry[largest] < List<List_entry>::entry[current])
			largest = current;
	return largest;
}

template <class List_entry>		//����
void Sortable_list<List_entry>::Swap(int low, int high)
{
	if (low != high)	//low����high����ִ��
	{
		List_entry temp = List<List_entry>::entry[low];
		List<List_entry>::entry[low] = List<List_entry>::entry[high];
		List<List_entry>::entry[high] = temp;
	}
}

template <class List_entry>		//ѡ������
void Sortable_list<List_entry>::selection_sort()
{
	for (int position = List<List_entry>::count - 1; position > 0; position--)
	{
		int Max = max_key(0, position);
		Swap(Max, position);
	}
}

template <class List_entry>		//ϣ�������ڲ���������
void Sortable_list<List_entry>::sort_interval(int start, int increment)
{
	int first_unsorted;
	int position;
	List_entry current;
	for (first_unsorted = start + increment; first_unsorted < List<List_entry>::count; first_unsorted += increment)
		if (List<List_entry>::entry[first_unsorted] < List<List_entry>::entry[first_unsorted - increment])
		{
			position = first_unsorted;
			current = List<List_entry>::entry[position];
			do {
				List<List_entry>::entry[position] = List<List_entry>::entry[position - increment];
				position -= increment;
			} while (position > 0 && List<List_entry>::entry[position - increment] > current);
			List<List_entry>::entry[position] = current;
		}
}

template <class List_entry>		//ϣ������
void Sortable_list<List_entry>::shell_sort()
{
	int increment, start;
	increment = List<List_entry>::count;
	do {
		increment = increment / 3 + 1;		//�ӱ���Ԫ����ԭ���ڵļ��
		for (start = 0; start < increment; start++)
			sort_interval(start, increment);
	} while (increment > 1);
}

template <class List_entry>		//����������λ��pivot
void Sortable_list<List_entry>::quick_sort_1()
{
	recursive_quick_sort_1(0, List<List_entry>::count - 1);
}

template <class List_entry>		//�ݹ��������ͷβ�м����λ��pivot(֧��),ɨ�跽ʽ�Ϳα���һ��
void Sortable_list<List_entry>::recursive_quick_sort_1(int low, int high)
{
	int pivot_position;
	if (low < high)
	{
		pivot_position = partition(low, high);
		recursive_quick_sort_1(low, pivot_position - 1);
		recursive_quick_sort_1(pivot_position + 1, high);
	}
}

template <class List_entry>		//����λ������
int Sortable_list<List_entry>::median(int a, int b, int c)
{
	if (List<List_entry>::entry[a] >= List<List_entry>::entry[b])
	{   if (List<List_entry>::entry[b] >= List<List_entry>::entry[c]) return b;
		else {  if (List<List_entry>::entry[a] >= List<List_entry>::entry[c]) return c;
				else return a;}}
	else {
		if (List<List_entry>::entry[a] >= List<List_entry>::entry[c]) return a;
		else {  if (List<List_entry>::entry[b] >= List<List_entry>::entry[c]) return c;
				else return b;}}
}

template <class List_entry>		//����֧���˳���ɨ�跽ʽ�Ϳα���һ��
int Sortable_list<List_entry>::partition(int low, int high)
{	
	int median_index = median(low, high, (low + high) / 2);
	//˫��ɨ�裬β���ȶ�
	std::swap(List<List_entry>::entry[median_index], List<List_entry>::entry[low]);
	List_entry pivot = List<List_entry>::entry[low];
	int left = low;
	int right = high;
	while (left < right)
	{
		//��β���ҵ�һ��С��֧�㣬Ӧ�÷ŵ�ǰ�ߵ�
		while (left < right && List<List_entry>::entry[right] >= pivot) right--;
		if (left < right) List<List_entry>::entry[left++] = List<List_entry>::entry[right];
		//��ͷ���ҵ�һ������֧�㣬Ӧ�÷ŵ���ߵ�
		while (left < right && List<List_entry>::entry[left] < pivot) left++;
		if (left < right) List<List_entry>::entry[right--] = List<List_entry>::entry[left];
	}
	//���ͷ����β��ͣ�µ�λ�þ���֧��Ӧ��λ��
	List<List_entry>::entry[left] = pivot;
	return left;
}