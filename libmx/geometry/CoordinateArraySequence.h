#ifndef _COORDINATE_ARRAY_SEQUENCE_H_
#define _COORDINATE_ARRAY_SEQUENCE_H_

#include "geometry/CoordinateSequence.h"

BEG_MX_NAMESPACE

template<class Type>
class LIBMX_API CoordinateArraySequence : public CoordinateSequence<Type>
{
public:
	CoordinateArraySequence()
	{
		_dimension = 1;
	}

	CoordinateArraySequence(unsigned int dimen,unsigned int sz=0)
	{
		_dimension  = dimen;
		_values.resize(sz*dimen);
	}

	virtual unsigned int size() const
	{
		return _values.size() / _dimension; 
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

	virtual void resize(unsigned int sz,const Type& defaultFill )
	{
		unsigned int osize = size();
		_values.resize(sz*_dimension);
		for(unsigned int i=osize*_dimension;i<size()*_dimension;i++)
		{
			_values[i] = defaultFill;
		}
	}

	void add(const Type& val)
	{
		assert(_dimension == 1);
		_values.push_back(val);
	}

	void add(const Type& val1,const Type& val2)
	{
		assert(_dimension == 2);
		_values.push_back(val1);
		_values.push_back(val2);
	}

	void add(const Type& val1,const Type& val2,const Type& val3)
	{
		_values.push_back(val1);
		_values.push_back(val2);
		_values.push_back(val3);
	}
private:
	unsigned int _dimension;
	std::vector<Type> _values;
};

typedef CoordinateArraySequence<int> CoordArraySequenceInt;
typedef CoordinateArraySequence<float> CoordArraySequenceFloat;
typedef CoordinateArraySequence<double> CoordArraySequenceDouble;

END_MX_NAMESPACE

#endif
