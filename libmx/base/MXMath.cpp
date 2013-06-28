#include "MXMath.h"

BEG_MX_NAMESPACE

int mx::MXMath::round( double dval )
{
	if(dval >= 0.0f)
	{
		return ((int)(dval + 0.5f));
	}

	return ((int)(dval - 0.5f));
}

END_MX_NAMESPACE
