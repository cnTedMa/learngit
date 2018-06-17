 ///
 /// @file    MutexLock.cc
 /// @author  Ted(18634365225@163.com)
 /// @date    2018-06-11 21:37:35
 ///
 
#include "MutexLock.h"
#include <iostream>

using namespace wd;

MutexLock::MutexLock()
:_isLocking(false)
{
	pthread_mutex_init(&_mutex,NULL);
}

MutexLock::~MutexLock()
{
	pthread_mutex_destroy(&_mutex);
}

void MutexLock::lock()
{
	pthread_mutex_lock(&_mutex);
	_isLocking = true;
}

void MutexLock::unlock()
{
	pthread_mutex_unlock(&_mutex);
	_isLocking = false;
}
