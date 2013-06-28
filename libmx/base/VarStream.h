#ifndef _VARSTREAM_H_
#define _VARSTREAM_H_

#include "base/Stream.h"
#include "base/VarSequence.h"

BEG_MX_NAMESPACE

class LIBMX_API VarStream : public Stream
{
public:
	VarStream(){};

	explicit VarStream(const char* data,int sz=-1);

	explicit VarStream(const MXString& str);
	
	explicit VarStream(const std::string& str);

	virtual char getChar();

	virtual bool putChar(char ch);

	virtual unsigned int capacity();

	virtual unsigned int size();

	virtual unsigned int readBytes(void* buf,unsigned int sz);

	virtual unsigned int writeBytes(void* buf,unsigned int sz);
private:
	VarSequence<char> _seq;
};

END_MX_NAMESPACE

#endif
