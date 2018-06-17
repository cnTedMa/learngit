 ///
 /// @file    namespace4.cc
 /// @author  Ted(18634365225@163.com)
 /// @date    2018-06-05 21:08:52
 ///
 
#include <iostream>
#include <stdio.h>

int number=10;

namespace A{
	using std::cout;
	using std::endl;
	int number=100;
	void display(int number){
		cout<<"形参number="<<number<<endl;
		cout<<"A::number="<<A::number<<endl;
		cout<<"全局变量number="<<::number<<endl;
	}
}

int main(){
	//cout<<"hello,world"<<endl;
	A::display(3);
	return 0;
}
