#include "base/Stream.h"
#include "base/ByteOrderValues.h"
#include "base/VarCoder.h"

BEG_MX_NAMESPACE

	bool Stream::seek(int pos,int where )
	{
		if(where == SEEK_SET)
		{
			return setPosition(pos);
		} 
		else if(where == SEEK_CUR)
		{
			return setPosition(position()+pos);
		} 
		else if(where == SEEK_END)
		{
			return setPosition(size()+pos-1);
		}
		return false;
	}
	
	unsigned int Stream::available()
	{
		return capacity()-position();
	}

	int Stream::getInt()
	{
		readBytes(_buf,sizeof(int));
		return ByteOrderValues::getInt(_buf,ByteOrderValues::ENDIAN_BIG);
	}

	int Stream::getVarInt()
	{
		return VarCoder::decode(*this);
	}

	bool Stream::getString(MXString& str)
	{
		int size = getVarInt();
		if(size > 0)
		{
			str.resize(size);
			readBytes((char*)(str.data()),size);
		}
		return true;
	}

	float Stream::getFloat()
	{
		readBytes(_buf,sizeof(float));
		return ByteOrderValues::getFloat(_buf,ByteOrderValues::ENDIAN_BIG);
	}

	double Stream::getDouble()
	{
		readBytes(_buf,sizeof(double));
		return ByteOrderValues::getDouble(_buf,ByteOrderValues::ENDIAN_BIG);
	}
	
	bool Stream::putInt( int i )
	{
		ByteOrderValues::putInt(i,_buf,ByteOrderValues::ENDIAN_BIG);
		return writeBytes(_buf,sizeof(int)) == sizeof(int);
	}
	
	bool Stream::putVarInt(int i)
	{
		VarCoder::encode(_buf,*this,i);
		return true;
	}

	bool Stream::putString(const MXString& str )
	{
		putVarInt(str.length());
		if(str.length()>0)
		{
			writeBytes((void*)str.data(),str.length());
		}
		return true;
	}


	bool Stream::putFloat( float f )
	{
		ByteOrderValues::putFloat(f,_buf,ByteOrderValues::ENDIAN_BIG);
		return writeBytes(_buf,sizeof(float)) == sizeof(float);
	}
	
	bool Stream::putDouble( double d )
	{
		ByteOrderValues::putDouble(d,_buf,ByteOrderValues::ENDIAN_BIG);
		return writeBytes(_buf,sizeof(double)) == sizeof(double);
	}

END_MX_NAMESPACE
