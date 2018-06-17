 ///
 /// @file    String.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-06-11 09:47:52
 ///

#include <stdio.h>
#include <string.h>
#include <limits>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;


class String
{
public:
	String()
	: _pstr(new char[1]())
	{
		cout << "String()" << endl;
	}

	String(const char * pstr)
	: _pstr(new char[strlen(pstr) + 1]())
	{
		cout << "String(const char *)" << endl;
		strcpy(_pstr, pstr);
	}

	String(const String & rhs)
	: _pstr(new char[strlen(rhs._pstr) + 1]())
	{
		strcpy(_pstr, rhs._pstr);
	}

	String & operator=(const String & rhs)
	{
		if(this != &rhs){
			delete [] _pstr;

			_pstr = new char[strlen(rhs._pstr) +1]();
			strcpy(_pstr, rhs._pstr);
		}
		return *this;
	}

	String & operator=(const char * rhs)
	{
		if(strcmp(this->_pstr,rhs)!=0)
		{
			delete [] _pstr;
			_pstr = new char[strlen(rhs) + 1]();
			strcpy(_pstr,rhs);
		}
		return *this;
	}

	String & operator+=(const String & rhs)
	{
		char * tmp = new char[strlen(_pstr) + strlen(rhs._pstr) + 1]();
		strcpy(tmp,_pstr);
		strcat(tmp,rhs._pstr);
		delete [] _pstr;
		_pstr = new char[sizeof(tmp) + 1]();
		strcpy(_pstr,tmp);
		delete [] tmp;
		return *this;
	}

	String & operator+=(const char * rhs)
	{
		char * tmp = new char[strlen(_pstr) + strlen(rhs) + 1]();
		strcpy(tmp,_pstr);
		strcat(tmp,rhs);
		delete [] _pstr;
		_pstr = new char[sizeof(tmp) + 1]();
		strcpy(_pstr,tmp);
		delete [] tmp;
		return *this;
	}

	char & operator[](std::size_t index)
	{
		static char nullchar = '\0';
		if(index >= strlen(_pstr))
		{
			return nullchar;
		}
		return _pstr[index];
	}

	const char & operator[](std::size_t index) const
	{
		static char nullchar;
		if(index >= strlen(_pstr))
		{
			return nullchar;
		}
		return _pstr[index];
		
	}

	std::size_t size() const
	{
		return strlen(_pstr);
	}

	const char* c_str() const
	{
		return _pstr;
	}

	friend bool operator==(const String &,const String &);
	friend bool operator!=(const String &,const String &);
	friend bool operator<(const String &,const String &);
	friend bool operator>(const String &,const String &);
	friend bool operator<=(const String &,const String &);
	friend bool operator>=(const String &,const String &);
	friend std::ostream &operator<<(std::ostream &os,const String &s);
	friend std::istream &operator>>(std::istream &is,String &s);
	void print() const
	{
		if(_pstr)
			cout << _pstr << endl;
	}

	~String()
	{
		delete [] _pstr;
		cout << "~String()" << endl;
	}
private:
char * _pstr;
};

bool operator==(const String & lhs,const String & rhs)
{
	if(strcmp(lhs._pstr,rhs._pstr)==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator!=(const String & lhs,const String & rhs)
{
	if(strcmp(lhs._pstr,rhs._pstr)==0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool operator<(const String & lhs,const String & rhs)
{
	size_t llen = lhs.size();
	size_t rlen = rhs.size();
	size_t len = (llen > rlen) ? rlen : llen;
	bool flag = false;
	for(size_t idx = 0;idx != len;++idx)
	{
		if(lhs[idx] > rhs[idx])
			return false;
		if(lhs[idx] < rhs[idx])
			flag = true;
	}
	if(flag == true)
	{
		return true;
	}
	if(flag == false && llen < rlen)
	{
		return true;
	}
	return false;
}

bool operator>(const String & lhs,const String & rhs)
{
	size_t llen = lhs.size();
	size_t rlen = rhs.size();
	size_t len = (llen > rlen) ? rlen : llen;
	bool flag = false;
	for(size_t idx = 0;idx != len;++idx)
	{
		if(lhs[idx] < rhs[idx])
			return false;
		if(lhs[idx] > rhs[idx])
			flag = true;
	}
	if(flag == true)
	{
		return true;
	}
	if(flag == false && llen > rlen)
	{
		return true;
	}
	return false;
}

bool operator<=(const String & lhs,const String & rhs)
{
	size_t llen = lhs.size();
	size_t rlen = rhs.size();
	size_t len = (llen > rlen) ? rlen : llen;
	bool flag = false;
	for(size_t idx = 0;idx != len;++idx)
	{
		if(lhs[idx] > rhs[idx])
			return false;
		if(lhs[idx] < rhs[idx])
			flag = true;
	}
	if(flag == true)
	{
		return true;
	}
	if(flag == false && llen <= rlen)
	{
		return true;
	}
	return false;
}

bool operator>=(const String & lhs,const String & rhs)
{
	size_t llen = lhs.size();
	size_t rlen = rhs.size();
	size_t len = (llen > rlen) ? rlen : llen;
	bool flag = false;
	for(size_t idx = 0;idx != len;++idx)
	{
		if(lhs[idx] < rhs[idx])
			return false;
		if(lhs[idx] > rhs[idx])
			flag = true;
	}
	if(flag == true)
	{
		return true;
	}
	if(flag == false && llen >= rlen)
	{
		return true;
	}
	return false;
}

std::ostream &operator<<(std::ostream &os,const String &s)
{
	for(size_t idx = 0;idx != s.size();++idx)
	{
		os << s[idx];
	}
	os << endl;
	return os;
}

std::istream &operator>>(std::istream &is,String &s)
{
	s = "\0";
	char *ch = new char[1]();
	while(is >> ch,!is.eof())
	{
		if(is.bad())
		{
			cout << "is has corrupted!" << endl;
			return is;
		}else if(is.fail())
		{
			is.clear();
			is.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		}
		s += ch;
	}
	return is;
}

String operator+(const String & lhs,const String & rhs)
{
	String tmp(lhs);
	tmp += rhs;
	return tmp;
}

String operator+(const String & lhs,const char * rhs)
{
	String tmp(lhs);
	tmp += rhs;
	return tmp;
}

String operator+(const char * lhs,const String & rhs)
{
	String tmp(lhs);
	tmp += rhs;
	return tmp;
}

int main(void)
{
	String s1 = ",world";
	String s2 = "hello";
	String s3 = "hello" + s1;
	cout << s3;
	return 0;
}
