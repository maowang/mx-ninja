#include "base/ReadWriteLock.h"

BEG_MX_NAMESPACE

ReadWriteLock::ReadWriteLock()
{
	valid = (pthread_rwlock_init(&rwlock,NULL) == 0);
}

ReadWriteLock::~ReadWriteLock()
{
	pthread_rwlock_destroy(&rwlock);
}

bool ReadWriteLock::rLock()
{
	if(!valid)return false;
	return pthread_rwlock_rdlock(&rwlock) == 0;
}

bool ReadWriteLock::wLock()
{
	if(!valid)return false;
	return pthread_rwlock_wrlock(&rwlock) == 0;
}

bool ReadWriteLock::unLock()
{
	if(!valid)return false;
	return pthread_rwlock_unlock(&rwlock) == 0;
}

bool ReadWriteLock::rTryLock()
{
	if(!valid)return false;
	return pthread_rwlock_tryrdlock(&rwlock) == 0;
}

bool ReadWriteLock::wTryLock()
{
	if(!valid)return false;
	return pthread_rwlock_trywrlock(&rwlock) == 0;
}

END_MX_NAMESAPCE
