#ifndef _TASK_H_
#define _TASK_H_

#include "base/Base.h"

BEG_MX_NAMESPACE

void do_task_func(void* arg);

class Task;

class LIBMX_API TaskCallBack
{
public:
	virtual void do_task_before(Task* task) = 0;
	virtual void do_task_after(Task* task) = 0;
};

class LIBMX_API Task
{
public:
	Task();
	void setCallback(TaskCallBack* callback);

	virtual ~Task();

	void Run();

protected:
	virtual bool do_task() = 0;

private:
	TaskCallBack* callback;
};

END_MX_NAMESAPCE

#endif
