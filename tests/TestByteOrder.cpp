#include "Test.h"
#include "base/ByteOrderValues.h"

USING_MX_NAMESPACE

TEST(ByteOrderValues_int)
{
	unsigned char buffer[4] = {0x01,0x02,0x03,0x04};
	int value = 0;
	value = ByteOrderValues::getInt(buffer,ByteOrderValues::ENDIAN_BIG);
	EXPECT_TRUE(value == 0x01020304);
	value = ByteOrderValues::getInt(buffer,ByteOrderValues::ENDIAN_LITTLE);
	EXPECT_TRUE(value == 0x04030201);

	unsigned char bufbig[4] = {0x01,0x02,0x03,0x04};
	ByteOrderValues::putInt(0x01020304,buffer,ByteOrderValues::ENDIAN_BIG);
	EXPECT_TRUE(memcmp(buffer,bufbig,4) == 0);

	unsigned char buflittle[4] = {0x04,0x03,0x02,0x01};
	ByteOrderValues::putInt(0x01020304,buffer,ByteOrderValues::ENDIAN_LITTLE);
	EXPECT_TRUE(memcmp(buffer,buflittle,4) == 0);
}

TEST(ByteOrderValues_long)
{
	long long longbig = 0x0102030405060708ll;
	long long longlittle = 0x0807060504030201ll;
	unsigned char buffer[8] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08};
	long long value = 0;
	value = ByteOrderValues::getLong(buffer,ByteOrderValues::ENDIAN_BIG);
	EXPECT_TRUE(value == longbig);
	value = ByteOrderValues::getLong(buffer,ByteOrderValues::ENDIAN_LITTLE);
	EXPECT_TRUE(value == longlittle);

	unsigned char bufbig[8] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08};
	ByteOrderValues::putLong(longbig,buffer,ByteOrderValues::ENDIAN_BIG);
	EXPECT_TRUE(memcmp(buffer,bufbig,8) == 0);

	unsigned char buflittle[8] = {0x08,0x07,0x06,0x05,0x04,0x03,0x02,0x01};
	ByteOrderValues::putLong(longlittle,buffer,ByteOrderValues::ENDIAN_LITTLE);
	EXPECT_TRUE(memcmp(buffer,buflittle,8) == 0);
}

TEST(ByteOrderValues_float)
{
	unsigned char buffer[4] = {0x01,0x02,0x03,0x04};
	float value = 0;
	value = ByteOrderValues::getFloat(buffer,ByteOrderValues::ENDIAN_BIG);
	EXPECT_TRUE(MX_FLOAT_EQUAL(value,2.3879393e-038));
	value = ByteOrderValues::getFloat(buffer,ByteOrderValues::ENDIAN_LITTLE);
	EXPECT_TRUE(MX_FLOAT_EQUAL(value,1.5399896e-036));

	unsigned char bufbig[4] = {0x01,0x02,0x03,0x04};
	unsigned char buflittle[4] = {0x04,0x03,0x02,0x01};

 	float fvalue = 0;
	memcpy(&fvalue,bufbig,4);
	ByteOrderValues::putFloat(fvalue,buffer,ByteOrderValues::ENDIAN_BIG);
	EXPECT_TRUE(memcmp(buffer,buflittle,4) == 0);

	ByteOrderValues::putFloat(fvalue,buffer,ByteOrderValues::ENDIAN_LITTLE);
	EXPECT_TRUE(memcmp(buffer,bufbig,4) == 0);
}

TEST(ByteOrderValues_double)
{
	unsigned char buffer[8] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08};
	double value = 0;
	value = ByteOrderValues::getDouble(buffer,ByteOrderValues::ENDIAN_BIG);
	EXPECT_TRUE(MX_DOUBLE_EQUAL(value,8.2078803991318393e-304));
	value = ByteOrderValues::getDouble(buffer,ByteOrderValues::ENDIAN_LITTLE);
	EXPECT_TRUE(MX_FLOAT_EQUAL(value,5.4476037220116050e-270));

	unsigned char bufbig[8] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08};
	unsigned char buflittle[8] = {0x08,0x07,0x06,0x05,0x04,0x03,0x02,0x01};

	double fvalue = 0;
	memcpy(&fvalue,bufbig,8);
	ByteOrderValues::putDouble(fvalue,buffer,ByteOrderValues::ENDIAN_BIG);
	EXPECT_TRUE(memcmp(buffer,buflittle,8) == 0);

	ByteOrderValues::putDouble(fvalue,buffer,ByteOrderValues::ENDIAN_LITTLE);
	EXPECT_TRUE(memcmp(buffer,bufbig,8) == 0);
}
