#ifndef _COORDINATE_H_
#define _COORDINATE_H_

#include "base/Base.h"
#include "base/FixedSequence.h"

BEG_MX_NAMESPACE

template<class Type>
class LIBMX_API Coord2d
{
public:
	Coord2d()
	{
		coord.setX(0,0);
		coord.setY(0,0);
	}

	Coord2d(const Type&x,const Type&y)
	{
		coord.setX(0,x);
		coord.setY(0,y);
	}

	const Type& getX() const
	{
		return coord.getX(0);
	}

	const Type& getY() const
	{
		return coord.getY(0);
	}

	void setX(const Type& x)
	{
		coord.setX(0,x);
	}

	void setY(const Type& y)
	{
		coord.setY(0,y);
	}
private:
	FixedSequence<Type,1,2> coord;
};

typedef Coord2d<int> Coord2dInt;
typedef Coord2d<float> Coord2dFloat;
typedef Coord2d<double> Coord2dDouble;

template<class Type>
class LIBMX_API Coord3d
{
public:
	Coord3d()
	{
		coord.setX(0,0);
		coord.setY(0,0);
		coord.setZ(0,0);
	}

	Coord3d(const Type&x,const Type&y,const Type& z)
	{
		coord.setX(0,x);
		coord.setY(0,y);
		coord.setZ(0,z);
	}

	const Type& getX() const
	{
		return coord.getX(0);
	}

	const Type& getY() const
	{
		return coord.getY(0);
	}

	const Type& getZ() const
	{
		return coord.getZ(0);
	}

	void setX(const Type& x)
	{
		coord.setX(0,x);
	}

	void setY(const Type& y)
	{
		coord.setY(0,y);
	}

	void setZ(const Type& z)
	{
		coord.setZ(0,z);
	}
private:
	FixedSequence<Type,1,3> coord;
};

typedef Coord3d<int> Coord3dInt;
typedef Coord3d<float> Coord3dFloat;
typedef Coord3d<double> Coord3dDouble;

END_MX_NAMESPACE

#endif
