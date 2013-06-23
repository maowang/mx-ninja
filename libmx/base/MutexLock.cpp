#include "base/MutexLock.h"

BEG_MX_NAMESPACE

MutexLock::MutexLock()
{
	pthread_mutex_init(&mutex,NULL);
}

MutexLock::~MutexLock()
{
	pthread_mutex_destroy(&mutex);
}

bool MutexLock::lock()
{
	return pthread_mutex_lock(&mutex) == 0;
}

bool MutexLock::unLock()
{
	return pthread_mutex_unlock(&mutex) == 0;
}

bool MutexLock::tryLock()
{
	return pthread_mutex_trylock(&mutex) == 0;
}

END_MX_NAMESAPCE
