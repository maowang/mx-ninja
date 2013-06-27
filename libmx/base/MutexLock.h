#ifndef _MUTEXLOCK_H_
#define _MUTEXLOCK_H_

#include "base/Base.h"

BEG_MX_NAMESPACE
class LIBMX_API MutexLock
{
public:
	MutexLock();
	~MutexLock();
	bool lock();
	bool unLock();
	bool tryLock();

private:
	bool valid;
	pthread_mutex_t mutex;
};

END_MX_NAMESPACE

#endif
