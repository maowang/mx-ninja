#include "base/VarStream.h"

BEG_MX_NAMESPACE

VarStream::VarStream(const char* data,int sz)
{
	assert(data != NULL);
	if(sz == -1)
	{
		sz = strlen(data);
	}

	if(sz > 0)
	{
		_seq.resize(sz,0);
		memcpy((char*)_seq.data(),data,sz);
	}
}

VarStream::VarStream(const MXString& str)
{
	_seq.resize(str.length(),0);
	memcpy((char*)_seq.data(),str.data(),str.length());
}

VarStream::VarStream(const std::string& str)
{
	_seq.resize(str.size(),0);
	memcpy((char*)_seq.data(),str.data(),str.size());
}

char VarStream::getChar()
{
	assert(available()>=1);
	return _seq.data()[_pos++];
}

bool VarStream::putChar( char ch )
{
	assert(available()>=1);
	((char*)_seq.data())[_pos++] = ch;
	return true;
}

unsigned int VarStream::capacity()
{
	return MX_MAXINT;
}

unsigned int VarStream::size()
{
	return _seq.size();
}

unsigned int VarStream::readBytes( void* buf,unsigned int sz )
{
	assert(available()>=sz);

	memcpy(buf,_seq.data() + _pos,sz);
	_pos += sz;
	return sz;
}

unsigned int VarStream::writeBytes( void* buf,unsigned int sz )
{
	assert(available()>=sz);

	if(_pos + sz > size())
	{
		_seq.resize(_pos + sz,0);	
	}
	memcpy((char*)_seq.data() + _pos,buf,sz);
	_pos += sz;
	return sz;
}

END_MX_NAMESPACE
