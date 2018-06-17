 ///
 /// @file    autoReleaseSingleton1.cc
 /// @author  Ted(18634365225@163.com)
 /// @date    2018-06-13 16:37:57
 ///
 

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Point
{
	public:
		Point(int ix,int iy)
		:_ix(ix)
		,_iy(iy)
		{
			cout << "Point(int,int)" << endl;
		}

		~Point()
		{
			cout << "~Point()" << endl;
		}

	private:
		int _ix;
		int _iy;
};

class Computer
{
	public:
	Computer(const char * brand,int price)
	:_brand(new char[strlen(brand) + 1]())
	,_price(price)
	{
		strcpy(_brand,brand);
		cout << "Computer(const char *,int)" << endl;
	}

	~Computer()
	{
		delete [] _brand;
		cout << "~Computer()" << endl;
	}

	private:
		char * _brand;
		int _price;
};

template<typename T>
class Singleton
{
	class AutoRelease
	{
	public:
		AutoRelease(){	cout << "AutoRelease()" << endl;	}
		 ~AutoRelease()
		{
			if(_pInstance)
				delete _pInstance;
			cout << "~AutoRelease()" << endl;
		}
	};
public:
	template<typename...Args>
	static T * getInstance(Args...args)
	{
		_auto;
		if(_pInstance == NULL)
			_pInstance = new Singleton(args...);
		return _pInstance->_t;
	}

private:
	template<typename...Args>
	Singleton(Args...args)
	{
		cout << "Singleton()" << endl;	
		_t = new T(args...);
	}
	~Singleton()
	{	
		delete _t;
		cout << "~Singleton()" << endl;	
	}
private:
	static Singleton<T> * _pInstance;
	T * _t;
	static AutoRelease _auto;
};

template<typename T>
Singleton<T> * Singleton<T>::_pInstance = NULL; 
template<typename T>
typename Singleton<T>::AutoRelease Singleton<T>::_auto;

//template<>
//Singleton<Computer>::AutoRelease Singleton<Computer>::_auto;


//template<>
//Singleton<Point>::AutoRelease Singleton<Point>::_auto;

int main()
{
	Computer * p1 = Singleton<Computer>::getInstance("Xiaomi",6666);
	Computer * p2 = Singleton<Computer>::getInstance("Xiaomi",6666);
	printf("p1 = %p\n",p1);
	printf("p2 = %p\n",p2);
	
	Point * p3 = Singleton<Point>::getInstance(1,2);
	Point * p4 = Singleton<Point>::getInstance(1,2);
	printf("p3 = %p\n",p3);
	printf("p4 = %p\n",p4);
	
	return 0;
}
