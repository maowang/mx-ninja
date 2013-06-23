#include "base/ReadWriteLock.h"

BEG_MX_NAMESPACE

ReadWriteLock::ReadWriteLock()
{
	pthread_rwlock_init(&rwlock,NULL);
}

ReadWriteLock::~ReadWriteLock()
{
	pthread_rwlock_destroy(&rwlock);
}

bool ReadWriteLock::rLock()
{
	return pthread_rwlock_rdlock(&rwlock) == 0;
}

bool ReadWriteLock::wLock()
{
	return pthread_rwlock_wrlock(&rwlock) == 0;
}

bool ReadWriteLock::unLock()
{
	return pthread_rwlock_unlock(&rwlock) == 0;
}

bool ReadWriteLock::rTryLock()
{
	return pthread_rwlock_tryrdlock(&rwlock) == 0;
}

bool ReadWriteLock::wTryLock()
{
	return pthread_rwlock_trywrlock(&rwlock) == 0;
}

END_MX_NAMESAPCE
