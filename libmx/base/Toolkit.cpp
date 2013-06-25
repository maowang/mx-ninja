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

END_MX_NAMESAPCE
