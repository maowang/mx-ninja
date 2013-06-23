#ifndef _CONDITION_H_
#define _CONDITION_H_

#include "base/Base.h"

BEG_MX_NAMESPACE
class LIBMX_API Condition
{
public:
	Condition();
	~Condition();

	bool wait();
	bool signal();
	bool broadcast();
	bool lock();

private:
	pthread_mutex_t mutex;
	pthread_cond_t cond;
};

END_MX_NAMESAPCE

#endif
