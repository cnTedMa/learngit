 ///
 /// @file    singleton.cc
 /// @author  Ted(18634365225@163.com)
 /// @date    2018-06-08 19:18:39
 ///
 
#include <iostream>
#include <stdio.h>
using std::cout;
using std::endl;

class Singleton{
public:
	static Singleton * getInstance(){
		if(!_pInstance){
			_pInstance=new Singleton();
		}
		return _pInstance;
	}
	static void destroy(){
		if(_pInstance){
			delete _pInstance;
		}
	}
private:
	Singleton(){
		cout << "Singleton()" << endl;
	}
	~Singleton(){
		cout << "~Singleton()" << endl;
	}
private:
	static Singleton * _pInstance;
};

Singleton * Singleton::_pInstance = NULL;

int main(){
	Singleton *pSingleton1=Singleton::getInstance();
	Singleton *pSingleton2=Singleton::getInstance();
	
	printf("pSingleton1 = %p\n",pSingleton1);
	printf("pSingleton2 = %p\n",pSingleton2);
	
	Singleton::destroy();

	return 0;
}
