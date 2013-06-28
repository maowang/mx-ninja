#ifndef _FIXEDSTREAM_H_
#define _FIXEDSTREAM_H_

#include "base/Stream.h"
#include "base/FixedSequence.h"

BEG_MX_NAMESPACE

class LIBMX_API FixedStream : public Stream
{
public:
	explicit FixedStream(const char* data,int sz=-1);
	explicit FixedStream(const MXString& str);
	explicit FixedStream(const std::string& str);
	~FixedStream();

	virtual char getChar();

	virtual bool putChar(char ch);

	virtual unsigned int capacity();

	virtual unsigned int size();

	virtual unsigned int readBytes(void* buf,unsigned int sz);

	virtual unsigned int writeBytes(void* buf,unsigned int sz);
private:
	FixedStream();
	FixedSequenceAlloc<char,1> _seq;
};

END_MX_NAMESPACE

#endif
