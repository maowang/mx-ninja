#ifndef _COORDINATE_H_
#define _COORDINATE_H_

#include "base/Base.h"

BEG_MX_NAMESPACE

class LIBMX_API Coordinate
{
public:
	 Coordinate();
	 Coordinate(double x, double y);
	 Coordinate(double x, double y, double z);
	 bool equals2D(const Coordinate& other) const;
	 bool equals3D(const Coordinate& other) const;
	 double distance2D(const Coordinate& p) const;
	 double distance3D(const Coordinate& p) const;
	 bool operator==(const Coordinate& other);
	 bool operator!=(const Coordinate& other);

private:
	double x;
	double y;
	double z;
};

END_MX_NAMESAPCE

#endif
