#include "base/Toolkit.h"

BEG_MX_NAMESPACE

void Toolkit::sleep( long long millisec )
{
#ifdef WIN32
	Sleep((int)millisec);
#else
	usleep(millisec * 1000);
#endif
}

long long Toolkit::currentTime()
{
#ifdef WIN32
	LARGE_INTEGER tick;
	LARGE_INTEGER timestamp;
	QueryPerformanceFrequency(&tick);
	QueryPerformanceCounter(&timestamp);
	return (timestamp.QuadPart % tick.QuadPart)*1000000/tick.QuadPart; 
#else
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (long long)tv.tv_sec*1000*1000+tv.tv_usec;
#endif
}

unsigned int Toolkit::threadId()
{
#ifdef WIN32
	return (unsigned int)pthread_self().p;
#else
	return (unsigned int)pthread_self();
#endif
	
}

END_MX_NAMESPACE
