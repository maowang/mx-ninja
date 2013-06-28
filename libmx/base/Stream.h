#ifndef _STREAM_H_
#define _STREAM_H_

#include "base/Base.h"
#include "base/MXString.h"

BEG_MX_NAMESPACE

class LIBMX_API Stream{
	public:
		Stream()
		{
			rewind();
		}

		virtual ~Stream()
		{
			close();
		}

		virtual unsigned int position()
		{
			return _pos;
		}

		virtual void close(){};

		void rewind()
		{
			_pos = 0;
		}

		bool seek(int pos,int where=SEEK_SET);

		unsigned int available();

		int getInt();

		int getVarInt();

		bool getString(MXString& str);

		float getFloat();

		double getDouble();

		bool putInt(int i);
		
		bool putVarInt(int i);

		bool putString(const MXString& str);
		
		bool putFloat(float f);
		
		bool putDouble(double d);

	public:
		virtual char getChar() = 0;

		virtual bool putChar(char ch) = 0;

		virtual unsigned int capacity()=0;

		virtual unsigned int size() = 0;

		virtual unsigned int readBytes(void* buf,unsigned int size)=0;

		virtual unsigned int writeBytes(void* buf,unsigned int size)=0;

	protected:
		virtual bool setPosition(unsigned int pos)=0;

		unsigned int _pos;
		unsigned char _buf[8];
	};

END_MX_NAMESPACE

#endif
