#include "base/ByteOrderValues.h"

BEG_MX_NAMESPACE

int ByteOrderValues::getInt(const unsigned char *buf, int byteOrder)
{
	if ( byteOrder == ENDIAN_BIG )
	{
		return  ((int) (buf[0]&0xff) <<24) |
			((int) (buf[1]&0xff) <<16) |
			((int) (buf[2]&0xff) <<8) |
			((int) (buf[3]&0xff) );
	}
	else // ENDIAN_LITTLE
	{
		assert(byteOrder == ENDIAN_LITTLE);

		return  ((int) (buf[3]&0xff) <<24) |
			((int) (buf[2]&0xff) <<16) |
			((int) (buf[1]&0xff) <<8) |
			((int) (buf[0]&0xff) );
	}
}

void ByteOrderValues::putInt(int intValue, unsigned char *buf, int byteOrder)
{
	if ( byteOrder == ENDIAN_BIG )
	{
		buf[0] = (unsigned char)(intValue >> 24);
		buf[1] = (unsigned char)(intValue >> 16);
		buf[2] = (unsigned char)(intValue >> 8);
		buf[3] = (unsigned char) intValue;
	}
	else // ENDIAN_LITTLE
	{
		assert(byteOrder == ENDIAN_LITTLE);

		buf[3] = (unsigned char)(intValue >> 24);
		buf[2] = (unsigned char)(intValue >> 16);
		buf[1] = (unsigned char)(intValue >> 8);
		buf[0] = (unsigned char) intValue;
	}
}

long long ByteOrderValues::getLong(const unsigned char *buf, int byteOrder)
{
	if ( byteOrder == ENDIAN_BIG )
	{
		return
			(long long) (buf[0]) << 56
			| (long long) (buf[1] & 0xff) << 48
			| (long long) (buf[2] & 0xff) << 40
			| (long long) (buf[3] & 0xff) << 32
			| (long long) (buf[4] & 0xff) << 24
			| (long long) (buf[5] & 0xff) << 16
			| (long long) (buf[6] & 0xff) <<  8
			| (long long) (buf[7] & 0xff);
	}
	else // ENDIAN_LITTLE
	{
		assert(byteOrder == ENDIAN_LITTLE);

		return
			(long long) (buf[7]) << 56
			| (long long) (buf[6] & 0xff) << 48
			| (long long) (buf[5] & 0xff) << 40
			| (long long) (buf[4] & 0xff) << 32
			| (long long) (buf[3] & 0xff) << 24
			| (long long) (buf[2] & 0xff) << 16
			| (long long) (buf[1] & 0xff) <<  8
			| (long long) (buf[0] & 0xff);
	}
}

void ByteOrderValues::putLong(long long longValue, unsigned char *buf, int byteOrder)
{
	if ( byteOrder == ENDIAN_BIG )
	{
		buf[0] = (unsigned char)(longValue >> 56);
		buf[1] = (unsigned char)(longValue >> 48);
		buf[2] = (unsigned char)(longValue >> 40);
		buf[3] = (unsigned char)(longValue >> 32);
		buf[4] = (unsigned char)(longValue >> 24);
		buf[5] = (unsigned char)(longValue >> 16);
		buf[6] = (unsigned char)(longValue >> 8);
		buf[7] = (unsigned char) longValue;
	}
	else // ENDIAN_LITTLE
	{
		assert(byteOrder == ENDIAN_LITTLE);

		buf[0] = (unsigned char) longValue;
		buf[1] = (unsigned char)(longValue >> 8);
		buf[2] = (unsigned char)(longValue >> 16);
		buf[3] = (unsigned char)(longValue >> 24);
		buf[4] = (unsigned char)(longValue >> 32);
		buf[5] = (unsigned char)(longValue >> 40);
		buf[6] = (unsigned char)(longValue >> 48);
		buf[7] = (unsigned char)(longValue >> 56);
	}
}

double ByteOrderValues::getDouble(const unsigned char *buf, int byteOrder)
{
	long long longValue = getLong(buf, byteOrder);
	double ret;
    memcpy(&ret, &longValue, sizeof(double));
	return ret;
}

void ByteOrderValues::putDouble(double doubleValue, unsigned char *buf, int byteOrder)
{
	long long longValue;
    memcpy(&longValue, &doubleValue, sizeof(double));
	putLong(longValue, buf, byteOrder);
}

float ByteOrderValues::getFloat(const unsigned char *buf, int byteOrder)
{
	int floatValue = getInt(buf, byteOrder);
	float ret;
	memcpy(&ret, &floatValue, sizeof(float));
	return ret;
}

void ByteOrderValues::putFloat(float floatValue, unsigned char *buf, int byteOrder)
{
	int intValue;
	memcpy(&intValue, &floatValue, sizeof(float));
	putInt(intValue, buf, byteOrder);
}

END_MX_NAMESPACE
