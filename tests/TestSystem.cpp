#include "Test.h"
#include "base/System.h"
#include "base/Toolkit.h"
#include "base/ThreadPool.h"

USING_MX_NAMESPACE

TEST(System_fun)
{
	EXPECT_TRUE(!System::getInstance().bigendian());
}

TEST(Toolkit_fun)
{
	Toolkit::sleep(100);
	long long cur = Toolkit::currentTime();
	printf("current usecs %lld\n",cur);
}

class RandTask : public Task
{
public:
	virtual bool do_task()
	{
		for(int i=0;i<10;i++)
		{
			printf("thread %d,rand %ud\n",Toolkit::threadId(),System::getInstance().random());
		}
		return true;
	}
};

TEST(System_rand)
{
	ThreadPool pool(3,10);
	pool.AddTask(new RandTask());
	pool.AddTask(new RandTask());
	pool.AddTask(new RandTask());
	Toolkit::sleep(500);
}