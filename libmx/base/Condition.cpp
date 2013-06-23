#include "base/Condition.h"

BEG_MX_NAMESPACE

Condition::Condition()
{
	pthread_cond_init(&cond,NULL);
	pthread_mutex_init(&mutex,NULL);
}

Condition::~Condition()
{
	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);
}

bool Condition::wait()
{
	return pthread_cond_wait(&cond,&mutex) == 0;
}

bool Condition::signal()
{
	return pthread_cond_signal(&cond) == 0;
}

bool Condition::broadcast()
{
	return pthread_cond_broadcast(&cond) == 0;
}

bool Condition::lock()
{
	return pthread_mutex_lock(&mutex) == 0;
}

END_MX_NAMESAPCE
