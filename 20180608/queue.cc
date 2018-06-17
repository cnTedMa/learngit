 ///
 /// @file    queue.cc
 /// @author  Ted(18634365225@163.com)
 /// @date    2018-06-08 19:57:44
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class myQueue{
public:
	myQueue()
	:_arr()
	,_phead(-1)
	,_ptail(-1)
	{
		cout << "myQueue()" << endl;
	}

	~myQueue(){
		cout << "~myQueue()" << endl;
	}

	void push(int x)
	{
		++_ptail;
		_ptail%=10;
		if(_ptail==_phead)
		{
			--_ptail;
			return;
		}
		_arr[_ptail]=x;
		cout << "push(int)" << endl;
	}

	void pop()
	{
		cout << "pop()" << endl;
		if(_ptail==_phead){
			return;
		}
		++_phead;
		_phead%=10;
	}

	int front()
	{
		cout << "front()" << endl;
		return _arr[_phead+1];
	}

	int back()
	{
		cout << "back()" << endl;
		return _arr[_ptail];
	}

	bool empty()
	{
		cout << "empty()" << endl;
		if(_phead==_ptail)
		{
			return true;
		}else{
			return false;
		}
	}

	bool full()
	{	
		cout << "full()" << endl;
		if((_ptail+1)%10==_phead)
		{
			return true;
		}else{
			return false;
		}
	}

	void print()
	{
		for(int i=_phead;i!=_ptail;++i,i%=10)
		{
			cout << _arr[(i+1)%10] << " " ;
		}
		cout << endl;
		cout << "print()" << endl;
	}

private:
	int _arr[10];
	int _phead;
	int _ptail;
};

void test0()
{
	myQueue q;
	q.push(10);
	q.print();
	q.push(12);
	q.print();
	q.push(13);
	q.print();
	cout << "front is " << q.front() << endl;
	cout << "back is " << q.back () << endl;
	q.pop();
	q.print();
	q.push(14);
	q.push(14);
	q.push(14);
	q.push(14);
	q.push(14);
	q.push(14);
	q.pop();
	q.pop();
	q.pop();
	q.pop();
	q.pop();
	q.pop();
	q.push(14);
	q.push(1);
	q.push(2);
	q.push(3);
	q.print();
}

int main()
{
	test0();
	return 0;
}
