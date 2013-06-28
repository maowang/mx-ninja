#ifndef _SEQUENCE_H_
#define _SEQUENCE_H_

#include "base/Base.h"

BEG_MX_NAMESPACE

template<class Type>
class LIBMX_API Sequence
{
public:
	Sequence(){};

	virtual ~Sequence(){};

	const Type& getX(unsigned int index) const
	{
		return getValue(index,1);
	}

	const Type& getY(unsigned int index) const
	{
		return getValue(index,2);
	}

	const Type& getZ(unsigned int index) const
	{
		return getValue(index,3);
	}

	void setX(unsigned int index,const Type& val)
	{
		setValue(index,1,val);
	}

	void setY(unsigned int index,const Type& val)
	{
		setValue(index,2,val);
	}

	void setZ(unsigned int index,const Type& val)
	{
		setValue(index,3,val);
	}

public:
	virtual void setValue(unsigned int index,unsigned int dim,const Type& val) = 0;

	virtual const Type& getValue(unsigned int index,unsigned int dim) const = 0;

	virtual unsigned int size() const = 0;
};

END_MX_NAMESPACE

#endif
