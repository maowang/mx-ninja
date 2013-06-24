#include "base/ThreadPool.h"

BEG_MX_NAMESPACE

ThreadPool::ThreadPool()
{
	pool = threadpool_create(1,255,0);
}

ThreadPool::ThreadPool( unsigned int threadsize,unsigned int tasksize )
{
	pool = threadpool_create(threadsize,tasksize,0);
}

ThreadPool::~ThreadPool()
{
	threadpool_destroy(pool,0);
}

bool ThreadPool::AddTask( Task* task )
{
	if(pool == NULL || task == NULL)
	{
		SAVE_DELETE(task);
		return false;
	}

	if(threadpool_add(pool,do_task_func,task,0) != 0)
	{
		SAVE_DELETE(task);
		return false;
	}

	return true;
}

END_MX_NAMESAPCE
