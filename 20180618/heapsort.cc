 ///
 /// @file    heapsort.cc
 /// @author  Ted(18634365225@163.com)
 /// @date    2018-06-18 20:07:42
 ///
 
#include <algorithm>
#include <iostream>
#include <queue>
using std::cout;
using std::endl;
using std::priority_queue;
using std::swap;

template <typename T, typename Compare = std::less<T> >
class HeapSort
{
public:
	HeapSort(T * arr, int size);
	void heapAdjust(int len, int index);
	void sort();
private:
	T * _arr;
	int _size;
};

template <typename T, typename Compare>
HeapSort<T,Compare>::HeapSort(T * arr, int size)
: _arr(arr)
, _size(size)
{
	cout << "HeapSort(T*,int)" << endl;
}

template <typename T, typename Compare>
void HeapSort<T,Compare>::heapAdjust(int len, int index)
{
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	int maxIdx = index;
	if(left < len && _arr[left] > _arr[maxIdx])
		maxIdx = left;
	if(right < len && _arr[right] > _arr[maxIdx])
		maxIdx = right;
	if(maxIdx != index)
	{
		swap(_arr[maxIdx], _arr[index]);
		heapAdjust(len, maxIdx);
	}
}

template <typename T, typename Compare>
void HeapSort<T,Compare>::sort()
{
	for(int i = _size / 2 - 1; i >= 0; --i)
	{
		heapAdjust(_size, i);
	}
	for(int i = _size - 1; i >= 1; --i)
	{
		swap(_arr[0], _arr[i]);
		heapAdjust(i, 0);
	}
}

int main()
{
	int array[8] = {8,1,14,3,21,5,7,10};
	HeapSort<int> hs(array, 8);
	hs.sort();
	for(auto ele: array)
	{
		cout << ele << " ";
	}
	cout << endl;
	return 0;
}
