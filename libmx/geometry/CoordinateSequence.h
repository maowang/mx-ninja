#ifndef _COORDINATE_SEQUENCE_H_
#define _COORDINATE_SEQUENCE_H_

#include "base/Base.h"

BEG_MX_NAMESPACE
class LIBMX_API Sequence
{
public:
	Sequence()
	{
		_dimension = 1;
	}

	Sequence(unsigned int dimen)
	{
		_dimension = dimen;
	}

	virtual ~Sequence(){};
	virtual unsigned int size() const = 0;
	virtual unsigned int dimension() const
	{
		return _dimension;
	}
protected:
	unsigned int _dimension;
};

template<class Type>
class LIBMX_API CoordinateSequence : public Sequence
{
public:
	CoordinateSequence(){};

	virtual ~CoordinateSequence(){};

	virtual void setValue(unsigned int index,unsigned int dim,const Type& val) = 0;

	virtual const Type& getValue(unsigned int index,unsigned int dim) const = 0;

	virtual void resize(unsigned int sz,const Type& defaultFill ) = 0;

	const Type& getX(unsigned int index) const
	{
		assert(_dimension > 0);
		return getValue(index,1);
	}

	const Type& getY(unsigned int index) const
	{
		assert(_dimension > 1);
		return getValue(index,2);
	}

	const Type& getZ(unsigned int index) const
	{
		assert(_dimension > 2);
		return getValue(index,3);
	}

	void setX(unsigned int index,const Type& val)
	{
		assert(_dimension > 0);
		setValue(index,1,val);
	}

	void setY(unsigned int index,const Type& val)
	{
		assert(_dimension > 0);
		setValue(index,2,val);
	}

	void setZ(unsigned int index,const Type& val)
	{
		assert(_dimension > 0);
		setValue(index,3,val);
	}
};

END_MX_NAMESAPCE

#endif
