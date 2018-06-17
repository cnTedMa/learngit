 ///
 /// @file    MutexLock.h
 /// @author  Ted(18634365225@163.com)
 /// @date    2018-06-11 21:30:15
 ///
 
#ifndef __WD_MUTEXLOCK_H__
#define __WD_MUTEXLOCK_H__

#include <pthread.h>

namespace wd
{
class MutexLock
{
public:
	MutexLock();
	~MutexLock();

	void lock();
	void unlock();
	
	pthread_mutex_t * getMutexLockPtr(){ return &_mutex;}
	MutexLock(const MutexLock &) = delete;
	MutexLock & operator = (const MutexLock &) = delete;

private:
	pthread_mutex_t _mutex;
	bool _isLocking;
};

class MutexLockGuard
{
public:
	MutexLockGuard(MutexLock & mutex)
	:_mutex(mutex)
	{
		_mutex.lock();
	}

	~MutexLockGuard()
	{
		_mutex.unlock();
	}

private:
	MutexLock & _mutex;
};

}

#endif
