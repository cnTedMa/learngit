 ///
 /// @file    text_txt_search.cc
 /// @author  Ted(18634365225@163.com)
 /// @date    2018-06-17 12:51:35
 ///
 
#include "txt_search.h"

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
using std::cin;

int main(int argc,char ** argv)
{
	if(argc != 2)
	{
		cout << "./txt_search filename" << endl;
		return 0;
	}
	txtSearch ts;
	ts.readFile(argv[1]);
	string word;
	while(cin >> word)
	{
		ts.query(word);
	}
	return 0;
}
