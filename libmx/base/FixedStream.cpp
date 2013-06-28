#include "base/FixedStream.h"

BEG_MX_NAMESPACE

FixedStream::FixedStream(const char* data,int sz)
	: _seq((sz == -1 ? strlen(data) : sz))
{
	assert(data != NULL);
	if(_seq.size() > 0)
		memcpy((char*)_seq.data(),data,_seq.size());
}

FixedStream::FixedStream(const MXString& str)
	: _seq(str.length())
{
	if(_seq.size() > 0)
		memcpy((char*)_seq.data(),str.data(),str.length());
}

FixedStream::FixedStream(const std::string& str)
	: _seq(str.size())
{
	if(_seq.size() > 0)
		memcpy((char*)_seq.data(),str.data(),str.size());
}

FixedStream::~FixedStream()
{

}

char FixedStream::getChar()
{
	assert(available()>=1);
	return _seq.data()[_pos++];
}

bool FixedStream::putChar( char ch )
{
	assert(available()>=1);
	((char*)_seq.data())[_pos++] = ch;
	return true;
}

unsigned int FixedStream::capacity()
{
	return _seq.size();
}

unsigned int FixedStream::size()
{
	return _seq.size();
}

unsigned int FixedStream::readBytes( void* buf,unsigned int sz )
{
	assert(available()>=sz);
	memcpy(buf,_seq.data() + _pos,sz);
	_pos += sz;
	return sz;
}

unsigned int FixedStream::writeBytes( void* buf,unsigned int sz )
{
	assert(available()>=sz);
	memcpy((char*)_seq.data() + _pos,buf,sz);
	_pos += sz;
	return sz;
}

END_MX_NAMESPACE
