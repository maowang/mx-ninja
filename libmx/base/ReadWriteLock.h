#ifndef _READWRITELOCK_H_
#define _READWRITELOCK_H_

#include "base/Base.h"

BEG_MX_NAMESPACE
class LIBMX_API ReadWriteLock
{
public:
	ReadWriteLock();
	~ReadWriteLock();
	bool rLock();
	bool wLock();
	bool unLock();
	bool rTryLock();
	bool wTryLock();

private:
	pthread_rwlock_t rwlock;
};

END_MX_NAMESAPCE

#endif
