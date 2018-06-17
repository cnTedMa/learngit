 ///
 /// @file    namespace2.cc
 /// @author  Ted(18634365225@163.com)
 /// @date    2018-06-05 20:37:37
 ///
 
#include <iostream>
#include <stdio.h>

using std::cout;
using std::endl;

void print(){
	cout<<"print()"<<endl;
}

namespace A{
	void show(){
		cout<<"A::show()"<<endl;
	}
}

namespace B{
	void display(){
		cout<<"B::display()"<<endl;
		A::show();
	}
}

namespace A{
	void display(){
		cout<<"A::display()"<<endl;
		B::display();
	}
	namespace C{
		void display(){
			cout<<"C::display()"<<endl;
		}
	}
}

int main(){
	A::display();
	B::display();
	A::C::display();
	::print();
	return 0;
}

