#include "Test.h"
#include "base/MutexLock.h"
#include "base/ReadWriteLock.h"
#include "base/ThreadPool.h"
#include "base/Toolkit.h"

USING_MX_NAMESPACE

int count = 0;
MutexLock lock;
ReadWriteLock rwlock;

class MutexLockTest : public Task
{
public:
	MutexLockTest()
	{
	}
protected:
	bool do_task()
	{
		for(int i=0;i<10000;i++)
		{
			lock.lock();
			count = count+1;
			lock.unLock();
		}
		return true;
	}
};

class ReadWriteLockTask : public Task
{
public:
	ReadWriteLockTask()
	{
	}

	void setWLock()
	{
		useRlock = false;
	}

	void setRLock()
	{
		useRlock = true;
	}
protected:
	bool do_task()
	{
		if(useRlock){
			rwlock.rLock();
		}else{
			rwlock.wLock();
		}

		for(int i=0;i<100000;i++)
		{
			count = count+1;
		}
		rwlock.unLock();
		return true;
	}
	
private:
	bool useRlock;
};

TEST(Lock_MutexLock)
{
	ThreadPool pool(10,200);
	count = 0;
	for(int i=0;i<100;i++)
	{
		MutexLockTest* task1 = new MutexLockTest();
		EXPECT_TRUE(pool.AddTask(task1));
	}

	Toolkit::sleep(5000);
	EXPECT_TRUE(count == 1000000);
}

TEST(Lock_ReadWriteLock)
{
	ThreadPool pool(10,200);
	count = 0;
	for(int i=0;i<100;i++)
	{
		ReadWriteLockTask* task1 = new ReadWriteLockTask();
		task1->setWLock();
		EXPECT_TRUE(pool.AddTask(task1));
	}

	Toolkit::sleep(5000);

	EXPECT_TRUE(count == 10000000);

	count = 0;

	for(int i=0;i<100;i++)
	{
		ReadWriteLockTask* task1 = new ReadWriteLockTask();
		task1->setRLock();
		EXPECT_TRUE(pool.AddTask(task1));
	}

	Toolkit::sleep(10000);

	EXPECT_TRUE(count != 10000000);
}

