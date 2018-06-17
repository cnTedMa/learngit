 ///
 /// @file    stack.cc
 /// @author  Ted(18634365225@163.com)
 /// @date    2018-06-08 19:31:43
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class myStack{
public:
	myStack()
	:_arr()
	 ,_pointer(-1)
	{
		cout << "myStack()" << endl;
	}
	~myStack()
	{
		cout << "~myStack()" << endl;
	}
	void push(int x)
	{
		cout << "push()" << endl;
		++_pointer;
		if(_pointer==10){
			return;
		}
		_arr[_pointer]=x;
	}
	void pop()
	{
		if(_pointer!=-1)
		{
			--_pointer;
		}
		cout << "pop()" << endl;
		
	}
	int top()
	{
		cout << "top()" << endl;
		return _arr[_pointer];
	}
	bool empty()
	{
		cout << "empty()" << endl;
		if(_pointer==-1)
		{
			return true;
		}else{
			return false;
		}
	}
	bool full()
	{
		cout << "full()" << endl;
		if(_pointer==9)
		{
			return true;
		}else{
			return false;
		}
	}
	void print()
	{
		for(int i=0;i<=_pointer;i++){
			cout << _arr[i] << " " ;
		}
		cout << endl;
		cout << "print()" << endl;
	}


private:
	int _arr[10];
	int _pointer;
};

void test0(){
	myStack s;
	s.print();
	s.push(10);
	s.print();
	s.push(12);
	s.print();
	s.push(14);
	s.print();
	cout << "top is " << s.top() << endl;
	s.pop();
	s.print();
	cout << "top is " << s.top() << endl;
}

int main(){
	test0();
	return 0;
}
