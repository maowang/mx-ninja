#ifndef _TOOLKIT_H_
#define _TOOLKIT_H_

#include "base/Base.h"

#ifdef WIN32
#include <Windows.h>
#else
#include <sys/time.h>
#endif

BEG_MX_NAMESPACE

class LIBMX_API Toolkit
{
public:
	static void sleep(long long millisec);

	static long long currentTime();

	static unsigned int threadId();
};

END_MX_NAMESPACE

#endif

