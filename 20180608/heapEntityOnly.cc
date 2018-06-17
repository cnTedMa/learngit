 ///
 /// @file    heapEntityOnly.cc
 /// @author  Ted(18634365225@163.com)
 /// @date    2018-06-08 20:50:17
 ///
 
#include <iostream>
#include <stdlib.h>
#include <string.h>
using std::cout;
using std::endl;

class Student
{
public:
	Student(int id,const char * name)
	:_id(id)
	,_name(new char[strlen(name)+1]())
	{
		cout << "Student(int,char*)" << endl;
		strcpy(_name,name);
	}

	void print() const
	{
		cout << "id: " << _id << endl
			<< "name: " << _name << endl;
	}

	void destroy()
	{
		delete this;
	}

private:
	~Student()
	{
		delete [] _name;
		cout << "~Student()" << endl;
	}

public:
	void * operator new(size_t sz)
	{
		cout << "void * operator new(size_t)" << endl;
		void * ret = malloc(sz);
		return ret;
	}

	void operator delete(void *ret)
	{
		free(ret);
		cout << "void operator delete(void*)" << endl;
	}
	
private:
	int _id;
	char *_name;
};


int main()
{
	Student *pstu=new Student(99,"Ted");
	pstu->print();
	pstu->destroy();
	return 0;
}

