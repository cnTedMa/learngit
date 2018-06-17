 ///
 /// @file    autoReleaseSingleton2.cc
 /// @author  Ted(18634365225@163.com)
 /// @date    2018-06-13 16:51:59
 ///

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>
using std::cout;
using std::endl;

//
//方案二：单例对象的自动释放
//	> atexit + pthread_once


class Singleton
{
public:
	static Singleton * getInstance()
	{
		pthread_once(&_once,init);
		return _pInstance;
	}

	static void init()
	{
		_pInstance = new Singleton;
		atexit(destroy);
	}

	static void destroy()
	{
		if(_pInstance)
			delete _pInstance;
	}

private:
	Singleton(){	cout << "Singleton()" << endl;	}
	~Singleton(){	cout << "~Singleton()" << endl;	}

private:
	static Singleton * _pInstance;
	static pthread_once_t _once;
};

Singleton * Singleton::_pInstance = NULL;//饿（懒）汉模式
pthread_once_t Singleton::_once = PTHREAD_ONCE_INIT;

int main()
{
	Singleton * p1 = Singleton::getInstance();
	Singleton * p2 = Singleton::getInstance();

	printf("p1 = %p\n",p1);
	printf("p2 = %p\n",p2);
	
	return 0;
}
