#include "Test.h"
#include "base/ThreadPool.h"
#include "base/Condition.h"
#include "base/Toolkit.h"
#include "base/Log.h"

USING_MX_NAMESPACE

Condition cond;

class TestTask1 : public Task
{
public:
	virtual bool do_task()
	{
		for(int i=0;i<10;i++)
		{
			cond.signal();
			MX_INFO("thread %d,notifiy other",Toolkit::threadId());
			Toolkit::sleep(100);
		}

		return true;
	}
};

class TestTask2 : public Task
{
public:
	virtual bool do_task()
	{
		for(int i=0;i<10;i++)
		{
			cond.wait();
			MX_INFO("thread %d,notified by other",Toolkit::threadId());
		}

		return true;
	}
};

TEST(Condition_wait)
{
	ThreadPool pool(2,2);
	pool.AddTask(new TestTask1());
	pool.AddTask(new TestTask2());

	Toolkit::sleep(2000);

	cond.signal();
}