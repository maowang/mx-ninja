#include "base/MutexLock.h"

BEG_MX_NAMESPACE

MutexLock::MutexLock()
{
	valid = (pthread_mutex_init(&mutex,NULL) == 0);
}

MutexLock::~MutexLock()
{
	pthread_mutex_destroy(&mutex);
}

bool MutexLock::lock()
{
	if(!valid)return false;
	return pthread_mutex_lock(&mutex) == 0;
}

bool MutexLock::unLock()
{
	if(!valid)return false;
	return pthread_mutex_unlock(&mutex) == 0;
}

bool MutexLock::tryLock()
{
	if(!valid)return false;
	return pthread_mutex_trylock(&mutex) == 0;
}

END_MX_NAMESAPCE
