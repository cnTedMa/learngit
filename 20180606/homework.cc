 ///
 /// @file    homework.cc
 /// @author  Ted(18634365225@163.com)
 /// @date    2018-06-06 19:38:35
 ///
 
#include "homework.h"

int main(){
	String s1;
	s1.print();
	String s2("hello");
	s2.print();
	String s3(s2);
	s3.print();
	String s4;
	s4.print();
	s4=s2;
	s4.print();
	return 0;
}

