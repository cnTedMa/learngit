 ///
 /// @file    namespace3.cc
 /// @author  Ted(18634365225@163.com)
 /// @date    2018-06-05 20:43:54
 ///
 
#include <iostream>
#include <stdio.h>

namespace A{
	void display(){
		std::cout<<"A::display()"<<std::endl;
	}
}
void cout(){
	printf("hello,world\n");
}

namespace B{
	void display(){
		std::cout<<"B::display()"<<std::endl;
	}
}

int main(){
	A::display();
	B::display();
	cout();
	return 0;
}
