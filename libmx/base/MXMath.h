#ifndef _MXMATH_H
#define _MXMATH_H

#include "base/Base.h"

BEG_MX_NAMESPACE

class LIBMX_API MXMath
{
public:
	static int fastRound(double dval) 
	{ 
		dval += 6755399441055744.0; 
		return *(int*)&dval; 
	} 

	static int round(double dval) 
	{
		if(dval >= 0.0f)
		{
			return ((int)(dval + 0.5f));
		}

		return ((int)(dval - 0.5f));
	}
};

END_MX_NAMESPACE

#endif
