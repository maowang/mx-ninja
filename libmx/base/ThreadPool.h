#ifndef _THREAD_POOL_H_
#define _THREAD_POOL_H_

#include "base/Base.h"
#include "base/Task.h"
#include "internal/threadpool.h"

BEG_MX_NAMESPACE
class LIBMX_API ThreadPool
{
public:
	ThreadPool();
	ThreadPool(unsigned int threadsize,unsigned int tasksize);
	~ThreadPool();

	bool AddTask(Task* task);
private:
	threadpool_t* pool;
};

END_MX_NAMESAPCE

#endif
