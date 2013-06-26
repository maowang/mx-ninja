#include "Test.h"
#include "base/System.h"
#include "base/Rand.h"
#include "base/Toolkit.h"
#include "base/ThreadPool.h"

USING_MX_NAMESPACE

TEST(System_fun)
{
	EXPECT_TRUE(!System::getInstance().bigendian());
}

TEST(Toolkit_fun)
{
	long long beg = Toolkit::currentTime();
	Toolkit::sleep(500);
	long long end = Toolkit::currentTime();
	printf("current usecs %lld\n",end - beg);
}

class RandTask : public Task
{
public:
	virtual bool do_task()
	{
		for(int i=0;i<10;i++)
		{
			printf("thread %d,rand %ud\n",Toolkit::threadId(),Rand::randUInt());
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

	for(int i=0;i<10;i++)
	{
		printf("%.6f\n",Rand::randDouble());
	}

	for(int i=0;i<10;i++)
	{
		printf("%d\n",Rand::randRange(3,6));
	}
}