#ifndef _BYTE_ORDER_VALUES_H_
#define _BYTE_ORDER_VALUES_H_

#include "base/Base.h"

BEG_MX_NAMESPACE

class LIBMX_API ByteOrderValues {

public:
    enum EndianType
    {
        ENDIAN_BIG = 0,
        ENDIAN_LITTLE = 1
    };

	static int getInt(const unsigned char *buf, int byteOrder);
	static void putInt(int intValue, unsigned char *buf, int byteOrder);

	static long long getLong(const unsigned char *buf, int byteOrder);
	static void putLong(long long longValue, unsigned char *buf, int byteOrder);

	static float getFloat(const unsigned char *buf, int byteOrder);
	static void putFloat(float floatValue, unsigned char *buf, int byteOrder);

	static double getDouble(const unsigned char *buf, int byteOrder);
	static void putDouble(double doubleValue, unsigned char *buf, int byteOrder);
};

END_MX_NAMESPACE

#endif
