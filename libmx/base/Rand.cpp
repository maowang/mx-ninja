#include "Rand.h"

BEG_MX_NAMESPACE

RandGen	g_RandGen	= RandGen((unsigned)time(NULL));

unsigned int RandGen::GetRand(unsigned int nStart, unsigned int nEnd)
{
	return (int)((nEnd-nStart)*g_RandGen.RandDouble()) + nStart;
}

END_MX_NAMESAPCE
