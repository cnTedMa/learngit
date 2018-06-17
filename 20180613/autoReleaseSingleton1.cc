 ///
 /// @file    autoReleaseSingleton1.cc
 /// @author  Ted(18634365225@163.com)
 /// @date    2018-06-13 16:37:57
 ///
 
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

//自动 --> 析构函数
//
//方案一：单例对象的自动释放
//	> 静态对象 + 嵌套类
//	> 跨平台的方案（平台无关性）

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
	static Singleton * getInstance()
	{
		if(_pInstance == NULL)
			_pInstance = new Singleton();
		return _pInstance;
	}

private:
	Singleton(){	cout << "Singleton()" << endl;	}
	~Singleton(){	cout << "~Singleton()" << endl;	}

private:
	static Singleton * _pInstance;
	static AutoRelease _auto;
};

Singleton * Singleton::_pInstance = getInstance();//饱汉模式
Singleton::AutoRelease Singleton::_auto;

int main()
{
	Singleton * p1 = Singleton::getInstance();
	Singleton * p2 = Singleton::getInstance();
	
	printf("p1 = %p\n",p1);
	printf("p2 = %p\n",p2);

	return 0;
}
