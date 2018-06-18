 ///
 /// @file    priority_queue.cc
 /// @author  Ted(18634365225@163.com)
 /// @date    2018-06-18 19:14:47
 ///
 
#include <math.h>
#include <iostream>
#include <queue>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::priority_queue;

void test0(void)
{
	//优先级队列默认情况下，元素出队是会按降序方式进行排列
	//而默认比较方式是小于符号，产生的是一个大顶堆
	//
	//其底层实现采用的是堆排序算法，用堆顶的元素与新添加进来的元素进行比较
	//如果返回true，则用新添加的元素替换堆顶的元素
	//
	int arr[10] = {4,1,3,8,6,9,5,2,7,0,};
	priority_queue<int> pqueue;
	for(int idx = 0;idx < 10;++idx)
	{
		pqueue.push(arr[idx]);
		cout << "当前队列之中，优先级最高的元素是:" << pqueue.top() << endl;
	}
	while(!pqueue.empty())
	{
		cout << pqueue.top() << " ";
		pqueue.pop();
	}
	cout << endl;
}

void test1(void)
{
	int arr[10] = {4,1,3,8,6,9,5,2,7,0,};
	priority_queue<int,vector<int>,std::greater<int> > pqueue;
	for(int idx = 0;idx < 10;++idx)
	{
		pqueue.push(arr[idx]);
		cout << "当前队列之中，优先级最高的元素是:" << pqueue.top() << endl;
	}

	while(!pqueue.empty())
	{
		cout << pqueue.top() << " ";
		pqueue.pop();
	}
	cout << endl;
}

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int, int)" << endl;
	}

	float distance() const
	{
		return sqrt(_ix * _ix + _iy * _iy);
	}

	friend std::ostream & operator<<(std::ostream & os, const Point & rhs);

private:
	int _ix;
	int _iy;
};

std::ostream & operator<<(std::ostream & os, const Point & rhs)
{
	os << "(" << rhs._ix << "," << rhs._iy << ")";
	return os;
}

struct Comparator
{
	bool operator()(const Point & lhs, const Point & rhs)
	{
		return lhs.distance() < rhs.distance();
	}
};

void test2(void)
{
	Point points[5] = {
		Point(1,2),
		Point(2,3),
		Point(3,4),
		Point(4,5),
		Point(5,6)
	};
	priority_queue<Point, vector<Point>, Comparator> pqueue(points, points + 5);
	while(!pqueue.empty())
	{
		cout << pqueue.top() << " ";
		pqueue.pop();
	}
	cout << endl;
}

int main(void)
{
	test0();
	cout << "---------------------------" << endl;
	test1();
	cout << "---------------------------" << endl;
	test2();
	return 0;
}
