 ///
 /// @file    testDictionary.cc
 /// @author  Ted(18634365225@163.com)
 /// @date    2018-06-11 20:39:25
 ///
 
#include "Dictionary.h"
#include <iostream>
#include <time.h>
using std::cout;
using std::endl;

int main()
{
	time_t begin, end;
	Dictionary dictionary;
	begin=time(NULL);
	dictionary.read("The_Holy_Bible.txt");
	dictionary.store("dictionary.txt");
	end=time(NULL);
	cout << "use: " << end-begin << "s" << endl;
	return 0;
}
