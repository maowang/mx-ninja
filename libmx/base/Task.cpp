#include "base/Task.h"

BEG_MX_NAMESPACE

void do_task_func( void* arg )
{
	if(arg != NULL)
	{
		Task* task = (Task*)arg;
		task->Run();
		SAVE_DELETE(task);
	}
}


Task::~Task()
{

}

Task::Task()
{
	callback = NULL;
}

void Task::setCallback(TaskCallBack* callback )
{
	this->callback = callback;
}

void Task::Run()
{
	if(callback != NULL)callback->do_task_before(this);
	do_task();
	if(callback != NULL)callback->do_task_after(this);
}

END_MX_NAMESPACE
