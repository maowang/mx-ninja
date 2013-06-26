#include "Test.h"
#include "base/MutexLock.h"
#include "base/ReadWriteLock.h"
#include "base/ThreadPool.h"
#include "base/Toolkit.h"
#include "base/Rand.h"

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

typedef struct  
{
	int a;
	int b;
}StructValue;
 
StructValue* testVal = NULL;

class RandTask : public Task
{
public:
	bool do_task()
	{
		for(int i=0;i<10000;i++)
		{
			if(Rand::randUInt() % 3 == 0)
			{
				SAVE_DELETE(testVal);
			}
			else if(Rand::randUInt() % 3 == 1)
			{
				SAVE_DELETE(testVal);
				testVal = new StructValue;
				testVal->a = 1;
				testVal->b = 1;
			}
			else
			{
				if(testVal != NULL)
				{
					testVal->a = testVal->a + testVal->b;
				}
			}
		}

		return true;
	}
};

TEST(MutexLock_delete)
{
// 	ThreadPool pool(30,200);
// 	for(int i=0;i<150;i++)
// 	{
// 		pool.AddTask(new RandTask());
// 	}
// 
// 	Toolkit::sleep(1000);
}