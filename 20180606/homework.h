 ///
 /// @file    homework.h
 /// @author  Ted(18634365225@163.com)
 /// @date    2018-06-06 19:39:17
 ///
#ifndef __HOMEWORK_H__
#define __HOMEWORK_H__
#include <iostream>
#include <string.h>
using namespace std;

class String{
public:
	String()
	:_pstr(nullptr)
	{
		cout << "String()" << endl;
	}
	String(const char *pstr)
	:_pstr(new char[strlen(pstr) + 1]())
	{
		cout << "String(const char *)" << endl;
		strcpy(_pstr, pstr);
	}
	String(const String & rhs)
	:_pstr(new char[strlen(rhs._pstr) + 1]())
	{
		cout << "String(const String & rhs)" << endl;
		strcpy(_pstr, rhs._pstr);
	}
	String & operator=(const String & rhs)
	{
		delete [] _pstr;
		_pstr = new char[strlen(rhs._pstr)+1]();
		strcpy(_pstr,rhs._pstr);
	}
	~String()
	{
		cout << "~String" << endl;
		delete [] _pstr;
		_pstr = NULL;
	}	

	void print()
	{
		cout << "print()" <<endl;
		if(_pstr==nullptr)
		{
			cout << "NULL" << endl;
		}else{
			cout << _pstr << endl;
		}
	}
private:
	char * _pstr;
};

#endif
