 ///
 /// @file    log4cpp.cc
 /// @author  Ted(18634365225@163.com)
 /// @date    2018-06-11 21:10:12
 ///
 

#include "Mylog.h"

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

void test()
{
	LogWarn("this is warn msg");
	LogInfo("this is info msg");
	LogError("this is error msg");
	LogDebug("this is debug msg");
}

int main()
{
	test();

	return 0;
}
