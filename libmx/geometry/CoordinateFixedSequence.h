#ifndef _COORDINATE_FIXED_SEQUENCE_H_
#define _COORDINATE_FIXED_SEQUENCE_H_

#include "geometry/CoordinateSequence.h"

BEG_MX_NAMESPACE

template<class Type,unsigned int _size,unsigned int _dimension>
class LIBMX_API CoordinateFixedSequence : public CoordinateSequence<Type>
{
public:
	CoordinateFixedSequence()
	{
	}

	virtual unsigned int size() const
	{
		return _size; 
	}

	virtual void setValue(unsigned int index,unsigned int dim,const Type& val)
	{
		assert(index < size() && dim <= _dimension);
		_values[index * _dimension + (dim - 1)] = val;
	}

	virtual const Type& getValue(unsigned int index,unsigned int dim) const
	{
		assert(index < size() && dim <= _dimension);
		return _values[index * _dimension + (dim - 1)];
	}
private:
	const CoordinateFixedSequence& operator=(const CoordinateFixedSequence& other);
	Type _values[_size*_dimension];
};

template<unsigned int sz=1,unsigned int dim=1>
class CoordFixedSequenceInt : public CoordinateFixedSequence<int,sz,dim>{};

template<unsigned int sz=1,unsigned int dim=1>
class CoordFixedSequenceFloat : public CoordinateFixedSequence<float,sz,dim>{};

template<unsigned int sz=1,unsigned int dim=1>
class CoordFixedSequenceDouble : public CoordinateFixedSequence<double,sz,dim>{};

END_MX_NAMESAPCE

#endif
