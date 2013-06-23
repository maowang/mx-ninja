#include "geometry/Coordinate.h"

BEG_MX_NAMESPACE

Coordinate::Coordinate()
{
	x = y = z = 0;
}

Coordinate::Coordinate(double x, double y)
	:x(x),y(y),z(0)
{

}

Coordinate::Coordinate(double x, double y, double z)
	:x(x),y(y),z(z)
{}

bool Coordinate::equals2D(const Coordinate& other) const
{
	if (x != other.x) return false;
	if (y != other.y) return false;
	return true;
}

bool Coordinate::equals3D(const Coordinate& other) const
{
	return (x == other.x) && ( y == other.y) && (z == other.z);
}

double Coordinate::distance2D(const Coordinate& p) const
{
	double dx = x - p.x;
	double dy = y - p.y;
	return std::sqrt(dx * dx + dy * dy);
}

double Coordinate::distance3D(const Coordinate& p) const
{
	double dx = x - p.x;
	double dy = y - p.y;
	double dz = z - p.z;
	return std::sqrt(dx * dx + dy * dy + dz * dz);
}

bool Coordinate::operator==(const Coordinate& other)
{
	return equals2D(other);
}

bool Coordinate::operator!=(const Coordinate& other)
{
	return !equals2D(other);
}

END_MX_NAMESAPCE
