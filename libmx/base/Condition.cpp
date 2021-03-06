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

void Condition::wait()
{
	if(pthread_mutex_lock(&mutex) == 0)
	{
		pthread_cond_wait(&cond,&mutex);
		pthread_mutex_unlock(&mutex);
	}
}

bool Condition::signal()
{
	return pthread_cond_signal(&cond) == 0;
}

END_MX_NAMESPACE
