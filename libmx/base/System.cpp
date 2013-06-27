#include "base/System.h"
#include "base/Toolkit.h"

BEG_MX_NAMESPACE

System System::system_ins;

static bool isbigendian()
{
	union{
		int uint;
		char uchar;
	}c;

	c.uint = 1;
	return (c.uchar == 0);
}

System::System()
{
	init();
}

void System::init()
{
	_bigendian = isbigendian();
}

const System& System::getInstance()
{
	return system_ins;
}

END_MX_NAMESPACE
