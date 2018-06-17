///
/// @file    templateQueue.cc
/// @author  Ted(18634365225@163.com)
/// @date    2018-06-14 19:39:04
///

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

template <typename T,int kSize = 10>
class Queue
{
	public:
		Queue();

		~Queue();

		bool full() const;

		bool empty() const;

		void push(const T &t);

		void pop();

		T front() const;

		T back() const;
	private:
		int _size;
		int _front;
		int _rear;
		T *_base;
};

	template <typename T,int kSize>
Queue<T,kSize>::Queue()
	:_size(kSize)
	,_front(0)
	,_rear(0)
	 ,_base(new T[kSize]())
{}

	template <typename T,int kSize>
Queue<T,kSize>::~Queue()
{
	delete [] _base;
}

template <typename T,int kSize>
bool Queue<T,kSize>::full() const
{
	return _front == (_rear + 1)%_size;
}

template <typename T,int kSize>
bool Queue<T,kSize>::empty() const
{
	return _front == _rear;
}

	template <typename T,int kSize>
void Queue<T,kSize>::push(const T &t)
{
	if(!full())
	{
		_base[_rear++] = t;
		_rear %= _size;
	}else
		cout << "queue is full" << endl;
}

	template <typename T,int kSize>
void Queue<T,kSize>::pop()
{
	if(!empty())
	{
		++_front;
		_front %= _size;
	}else
		cout << "queue is empty" << endl;
}

template <typename T,int kSize>
T Queue<T,kSize>::front() const
{
	return _base[_front];
}

template <typename T,int kSize>
T Queue<T,kSize>::back() const
{
	return _base[(_rear - 1 - _size)%_size];
}
int main(void)
{
	Queue<int> queue;
	cout << "此时queue是否为空?" << queue.empty() << endl;
	queue.push(1);
	cout << "此时queue是否为空?" << queue.empty() << endl;

	for(int idx = 2; idx != 12; ++idx)
	{
		queue.push(idx);
	}
	cout << "此时queue是否已满?" << queue.full() << endl;

	cout << "此时队头元素是:" << queue.front() << endl;
	cout << "此时队尾元素是:" << queue.back() << endl;

	queue.pop();
	queue.push(11);
	cout << "元素出队，又进队之后:" << endl;
	cout << "此时队头元素是:" << queue.front() << endl;
	cout << "此时队尾元素是:" << queue.back() << endl;

	while(!queue.empty())
	{
		cout << queue.front() << endl;
		queue.pop();
	}
	cout << "此时queue是否为空?" << queue.empty() << endl;
	return 0;
}
