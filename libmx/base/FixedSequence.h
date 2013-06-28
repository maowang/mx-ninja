#ifndef _FIXED_SEQUENCE_H_
#define _FIXED_SEQUENCE_H_

#include "base/Sequence.h"

BEG_MX_NAMESPACE

template<class Type,unsigned int _dimension>
class LIBMX_API FixedSequenceAlloc : public Sequence<Type>
{
public:
	FixedSequenceAlloc(unsigned int sz)
	{
		_values = new Type[_dimension * sz];
		_size = 0;
		if(_values != NULL)
		{
			_size = sz;
		}
	}

	~FixedSequenceAlloc()
	{
		delete[] _values;
	}

	virtual unsigned int size() const
	{
		return _size; 
	}

	virtual void setValue(unsigned int index,unsigned int dim,const Type& val)
	{
		if(index >= size() || dim > _dimension)return;

		_values[index * _dimension + (dim - 1)] = val;
	}

	virtual const Type& getValue(unsigned int index,unsigned int dim) const
	{
		assert(index < size() || dim <= _dimension);
		return _values[index * _dimension + (dim - 1)];
	}

	const Type* data()
	{
		return _values;
	}
private:
	const FixedSequenceAlloc& operator=(const FixedSequenceAlloc& other);
	Type* _values;
	unsigned int _size;
};

template<class Type,unsigned int _size,unsigned int _dimension>
class LIBMX_API FixedSequence : public Sequence<Type>
{
public:
	FixedSequence()
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

	const Type* data()
	{
		return _values;
	}
private:
	const FixedSequence& operator=(const FixedSequence& other);
	Type _values[_size*_dimension];
};

template<unsigned int sz=1,unsigned int dim=1>
class FixedSequenceInt : public FixedSequence<int,sz,dim>{};

template<unsigned int sz=1,unsigned int dim=1>
class FixedSequenceFloat : public FixedSequence<float,sz,dim>{};

template<unsigned int sz=1,unsigned int dim=1>
class FixedSequenceDouble : public FixedSequence<double,sz,dim>{};

END_MX_NAMESPACE

#endif
