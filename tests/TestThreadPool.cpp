#include "Test.h"
#include "base/Toolkit.h"
#include "base/ThreadPool.h"
#include "base/Log.h"

USING_MX_NAMESPACE

class TestCallBack : public TaskCallBack
{
public:
	void do_task_before(Task* task)
	{
		MX_INFO("before task run...,task info:%d\n",task);
	}

	void do_task_after(Task* task)
	{
		MX_INFO("after task run...,task info:%d\n",task);
	}
};

class TestTask : public Task
{
public:
	TestTask(const std::string& tag)
	{
		this->tag = tag;
	}
protected:
	bool do_task()
	{
		for(int i=0;i<10;i++)
		{
			Toolkit::sleep(100);
			MX_INFO("thread:%s,count:%d\n",tag.c_str(),i);
		}
		return true;
	}
private:
	std::string tag;
};

TEST(ThreadPool_SingleThread)
{
	TestCallBack callback;
	ThreadPool pool(1,2);
	TestTask* task1 = new TestTask("task1");
	TestTask* task2 = new TestTask("task2");
	TestTask* task3 = new TestTask("task3");

	task1->setCallback(&callback);
	task2->setCallback(&callback);
	task3->setCallback(&callback);
	EXPECT_TRUE(pool.AddTask(task1));
	EXPECT_TRUE(pool.AddTask(task2));
	EXPECT_FALSE(pool.AddTask(task3));

	Toolkit::sleep(1000);
}

TEST(ThreadPool_MultiThread)
{
	TestCallBack callback;
	ThreadPool pool(3,255);
	TestTask* task1 = new TestTask("task1");
	TestTask* task2 = new TestTask("task2");
	TestTask* task3 = new TestTask("task3");

	task1->setCallback(&callback);
	task2->setCallback(&callback);
	task3->setCallback(&callback);
	EXPECT_TRUE(pool.AddTask(task1));
	EXPECT_TRUE(pool.AddTask(task2));
	EXPECT_TRUE(pool.AddTask(task3));

	Toolkit::sleep(1000);
}

TEST(ThreadPool_AddTaskFailed)
{
	TestCallBack callback;
	ThreadPool pool;
	for(int i=0;i<1000;i++)
	{
		pool.AddTask(NULL);
	}

	Toolkit::sleep(1000);
}