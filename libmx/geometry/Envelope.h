#ifndef _ENVELOP_H_
#define _ENVELOP_H_

#include "base/Base.h"
#include "geometry/Coordinate.h"
#include "geometry/CoordinateFixedSequence.h"

BEG_MX_NAMESPACE

template<class Type>
class LIBMX_API Envelope
{
public:
	Envelope(void)
	{
		setToNull();
	}

	Envelope(const Type& x1,const Type& y1, const Type& x2,  const Type& y2)
	{
		init(x1,y1,x2,y2);
	}

	~Envelope(void){}

	void init(const Type& x1, const Type& y1,const Type& x2,  const Type& y2)
	{
		_coords.setX(0,MX_MIN(x1,x2));
		_coords.setY(0,MX_MIN(y1,y2));
		_coords.setX(1,MX_MAX(x1,x2));
		_coords.setY(1,MX_MAX(y1,y2));
	}

	void setToNull()
	{
		_coords.setX(0,0);
		_coords.setY(0,0);
		_coords.setX(1,-1);
		_coords.setY(1,-1);
	}

	bool isNull() const
	{
		return _coords.getX(0) > _coords.getX(1) ||
			   _coords.getY(0) > _coords.getY(1);
	}

	const Type& minX() const
	{
		return _coords.getX(0);
	}

	const Type& minY() const
	{
		return _coords.getY(0);
	}

	const Type& maxX() const
	{
		return _coords.getX(1);
	}

	const Type& maxY() const
	{
		return _coords.getY(1);
	}

	Type width() const
	{
		if(isNull())return 0;
		return _coords.getX(1) - _coords.getX(0);
	}

	Type height() const
	{
		if(isNull())return 0;
		return _coords.getY(1) - _coords.getY(0);
	}

	bool center(Coord2dDouble& coord) const
	{
		if(isNull())return false;
		coord.setX((_coords.getX(0) + _coords.getX(1)) / 2.0);
		coord.setY((_coords.getY(0) + _coords.getY(1)) / 2.0);
		return true;
	}

	void expandToInclude(const Coord2d<Type>& coord)
	{
		expandToInclude(coord.getX(),coord.getY());
	}

	void expandToInclude(const Type& x, const Type& y)
	{
		if(isNull())
		{
			init(x,y,x,y);
		}
		else
		{
			_coords.setX(0,MX_MIN(x,_coords.getX(0)));
			_coords.setY(0,MX_MIN(y,_coords.getY(0)));
			_coords.setX(1,MX_MAX(x,_coords.getX(1)));
			_coords.setY(1,MX_MAX(y,_coords.getY(1)));
		}
	}
	
	void expandToInclude(const Envelope& other)
	{
		if(other.isNull())return;

		if(isNull())
		{
			init(other.minX(),other.minY(),other.maxX(),other.maxY());
		}
		else
		{
			_coords.setX(0,MX_MIN(other.minX(),_coords.getX(0)));
			_coords.setY(0,MX_MIN(other.minY(),_coords.getY(0)));
			_coords.setX(1,MX_MAX(other.maxX(),_coords.getX(1)));
			_coords.setY(1,MX_MAX(other.maxY(),_coords.getY(1)));
		}
	}

	void expand(const Type& deltaX, const Type& deltaY)
	{
		if(isNull())return;
		_coords.setX(0,_coords.getX(0) - deltaX);
		_coords.setY(0,_coords.getY(0) - deltaY);
		_coords.setX(1,_coords.getX(1) + deltaX);
		_coords.setY(1,_coords.getY(1) + deltaY);
	}

	bool contains(Coord2d<Type>& coord) const
	{
		return contains(coord.getX(),coord.getY());
	}

	bool contains(const Type& x, const Type& y) const
	{
		if(isNull())return false;

		return x >= _coords.getX(0) && x <= _coords.getX(1) &&
			y >= _coords.getY(0) && y <= _coords.getY(1);
	}

	bool contains(const Envelope& other) const
	{
		if(other.isNull() || isNull())return false;

		return other.minX() >= _coords.getX(0) && other.maxX() <= _coords.getX(1) &&
			other.minY() >= _coords.getY(0) && other.maxY() <= _coords.getY(1);
	}

	bool intersects(const Envelope& other) const
	{
		if(isNull() || other.isNull())return false;

		return other.maxX() >= _coords.getX(0) && other.minX() <= _coords.getX(1) &&
			other.maxY() >= _coords.getY(0) && other.minY() <= _coords.getY(1);
	}
private:
	CoordinateFixedSequence<Type,2,2> _coords;
};

typedef Envelope<int> EnvelopeInt;
typedef Envelope<float> EnvelopeFloat;
typedef Envelope<double> EnvelopeDouble;

END_MX_NAMESAPCE

#endif
