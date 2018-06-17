 ///
 /// @file    stackEntityOnly.cc
 /// @author  Ted(18634365225@163.com)
 /// @date    2018-06-08 20:35:42
 ///
 
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
class Student
{
public:
	Student(int id,const char * name)
	:_id(id)
	,_name(new char[strlen(name)+1]())
	{
		cout << "Student()" << endl;
		strcpy(_name,name);
	}

	void print() const
	{
		cout << "id: " << _id << endl
			<< "name: "<< _name << endl;
	}

	~Student()
	{
		delete [] _name;
		cout << "~Student()" << endl;
	}

private:
	void * operator new(size_t);
	void operator delete(void*);

private:
	int _id;
	char * _name;
};

int main(){
	Student s1(99,"ted");
	s1.print();
	//Student * pstu=new Student(100,"lisa");
	//pstu->print();
	return 0;
}
