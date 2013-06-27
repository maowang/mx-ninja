#include "Test.h"
#include "base/System.h"
#include "base/Rand.h"
#include "base/Toolkit.h"
#include "base/ThreadPool.h"
#include "base/QSort.h"

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

TEST(QSort_sort)
{
	std::vector<int> array;
	array.push_back(10);
	array.push_back(3);
	array.push_back(4);
	array.push_back(1);
	array.push_back(4);

	QSort<int>::sort(array,true);
	EXPECT_TRUE(array[0]==1);
	EXPECT_TRUE(array[1]==3);
	EXPECT_TRUE(array[2]==4);
	EXPECT_TRUE(array[3]==4);
	EXPECT_TRUE(array[4]==10);

	QSort<int>::sort(array,false);
	EXPECT_TRUE(array[0]==10);
	EXPECT_TRUE(array[1]==4);
	EXPECT_TRUE(array[2]==4);
	EXPECT_TRUE(array[3]==3);
	EXPECT_TRUE(array[4]==1);
}

TEST(Log_log)
{
	MX_INFO("test info message!");
	MX_NOTIFY("test notify message!");
	MX_WARNING("test warning message!");
	MX_ERROR("test error message!");
}
