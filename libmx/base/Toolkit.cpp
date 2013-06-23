#include "base/Toolkit.h"

BEG_MX_NAMESPACE

void Toolkit::sleep( int millisec )
{
#ifdef WIN32
	Sleep(millisec);
#endif
}

END_MX_NAMESAPCE
