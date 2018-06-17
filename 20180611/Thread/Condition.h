 ///
 /// @file    Condition.h
 /// @author  Ted(18634365225@163.com)
 /// @date    2018-06-11 21:40:15
 ///
 
#ifndef __WD_CONDITION_H__
#define __WD_CONDITION_H__
#include <pthread.h>

namespace wd
{
class MutexLock;

class Condition
{
public:
	Condition(MutexLock & mutex);
	~Condition();

	void wait();
	void notify();
	void notifyAll();

	Condition(const Condition &) = delete;
	Condition & operator = (const Condition &) = delete;

private:
	pthread_cond_t _cond;
	MutexLock & _mutex;
};

}

#endif
