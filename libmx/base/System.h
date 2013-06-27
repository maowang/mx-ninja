#ifndef _SYSTEM_H
#define _SYSTEM_H

#include "base/Base.h"
#include "base/Log.h"

BEG_MX_NAMESPACE

class LIBMX_API System
{
public:
	static const System& getInstance();

	bool bigendian() const 
	{
		return _bigendian;
	}

private:
	System();
	System(const System& other);
	const System& operator=(const System& other);
	void init();

	static System system_ins;

	bool _bigendian;
};

END_MX_NAMESPACE
#endif
