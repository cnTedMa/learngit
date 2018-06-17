 ///
 /// @file    testThread.cc
 /// @author  Ted(18634365225@163.com)
 /// @date    2018-06-11 21:47:12
 ///
 
#include "MutexLock.h"
#include "Condition.h"

#include <unistd.h>
#include <iostream>
using std::cout;
using std::endl;
using namespace wd;

MutexLock gMutex;
Condition gCondition(gMutex);

int gCounter = 0;
bool gFlag = false;

void * threadFunc1(void * arg)
{
	int cnt = 10;
	while(cnt--)
	{
		MutexLockGuard autoLock(gMutex);
		if(gFlag)
		{
			gCondition.wait();
		}
		++gCounter;
		cout << pthread_self() << ":gCounter = " << gCounter << endl;
		if(!gFlag)
		{
			gFlag = true;
			gCondition.notify();
		}
		sleep(1);
	}
	return NULL;
}

void * threadFunc2(void * arg)
{
	int cnt = 10;
	while(cnt--)
	{
		MutexLockGuard autoLock(gMutex);
		if(!gFlag)
		{
			gCondition.wait();
		}

		++gCounter;
		cout << pthread_self() << ":gCounter = " << gCounter << endl;
		if(gFlag)
		{
			gFlag = false;
			gCondition.notify();
		}
		sleep(1);
	}
	return NULL;
}

int main()
{
	pthread_t thread1;
	pthread_t thread2;

	pthread_create(&thread1,NULL,threadFunc1,NULL);
	pthread_create(&thread2,NULL,threadFunc2,NULL);

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);

	return 0;
}
