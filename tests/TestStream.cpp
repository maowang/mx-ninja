#include "Test.h"
#include "base/FixedStream.h"
#include "base/VarStream.h"

USING_MX_NAMESPACE

void CheckStream(Stream & stream)
{
	EXPECT_TRUE(stream.size() == 13);
	EXPECT_TRUE(stream.position() == 0);

	EXPECT_TRUE(stream.getChar() == 'a');
	EXPECT_TRUE(stream.getChar() == 'b');
	EXPECT_TRUE(stream.getChar() == 'c');
	EXPECT_TRUE(stream.getChar() == 'd');
	EXPECT_TRUE(stream.getChar() == 'e');
	EXPECT_TRUE(stream.getChar() == 'f');
	EXPECT_TRUE(stream.getChar() == 'g');

	stream.rewind();
	EXPECT_TRUE(stream.position() == 0);
	EXPECT_TRUE(stream.putChar('g'));
	EXPECT_TRUE(stream.putChar('f'));
	EXPECT_TRUE(stream.putChar('e'));
	EXPECT_TRUE(stream.putChar('d'));
	EXPECT_TRUE(stream.putChar('c'));
	EXPECT_TRUE(stream.putChar('b'));
	EXPECT_TRUE(stream.putChar('a'));

	stream.rewind();
	EXPECT_TRUE(stream.getChar() == 'g');
	EXPECT_TRUE(stream.getChar() == 'f');
	EXPECT_TRUE(stream.getChar() == 'e');
	EXPECT_TRUE(stream.getChar() == 'd');
	EXPECT_TRUE(stream.getChar() == 'c');
	EXPECT_TRUE(stream.getChar() == 'b');
	EXPECT_TRUE(stream.getChar() == 'a');

	// test int value
	stream.seek(3);
	EXPECT_TRUE(stream.putInt(10));
	EXPECT_TRUE(stream.position() == 7);

	stream.seek(3);
	EXPECT_TRUE(stream.getInt() == 10);
	EXPECT_TRUE(stream.position() == 7);

	// test float value
	stream.seek(3);
	EXPECT_TRUE(stream.putFloat(10.0));
	EXPECT_TRUE(stream.position() == 7);

	stream.seek(3);
	EXPECT_TRUE(stream.getFloat() == 10.0);
	EXPECT_TRUE(stream.position() == 7);

	// test double value
	stream.seek(3);
	EXPECT_TRUE(stream.putDouble(10.0));
	EXPECT_TRUE(stream.position() == 11);

	stream.seek(3);
	EXPECT_TRUE(stream.getDouble() == 10.0);
	EXPECT_TRUE(stream.position() == 11);
}

TEST(FixedStream_getput)
{
	FixedStream streamFix("abcdefg--++--");
	EXPECT_TRUE(streamFix.capacity() == 13);
	CheckStream(streamFix);

	VarStream streamVar("abcdefg--++--");
	EXPECT_TRUE(streamVar.capacity() == MX_MAXINT);
	CheckStream(streamVar);

	MXString mxString("abcdefg--++--");
	VarStream streamVarStr(mxString);
	FixedStream streamFixStr(mxString);
	CheckStream(streamVarStr);
	CheckStream(streamFixStr);

	std::string stdString("abcdefg--++--");
	VarStream streamVarStdStr(stdString);
	FixedStream streamFixStdStr(stdString);
	CheckStream(streamVarStdStr);
	CheckStream(streamFixStdStr);
}

TEST(VarStream_Append)
{
	VarStream streamInt;

	streamInt.rewind();
	for(int i=0;i<100;i++)
	{
		EXPECT_TRUE(streamInt.putInt(i));
	}

	streamInt.rewind();
	for(int i=0;i<100;i++)
	{
		EXPECT_TRUE(streamInt.getInt() == i);
	}

	VarStream streamFloat;
	streamFloat.rewind();
	for(int i=0;i<100;i++)
	{
		EXPECT_TRUE(streamFloat.putFloat((float)i));
	}

	streamFloat.rewind();
	for(int i=0;i<100;i++)
	{
		EXPECT_TRUE(streamFloat.getFloat() == (float)i);
	}

	VarStream streamDouble;
	streamDouble.rewind();
	for(int i=0;i<100;i++)
	{
		EXPECT_TRUE(streamDouble.putDouble(i));
	}

	streamDouble.rewind();
	for(int i=0;i<100;i++)
	{
		EXPECT_TRUE(streamDouble.getDouble() == i);
	}

	VarStream streamVarInt;

	streamVarInt.rewind();
	for(int i=0;i<10000;i++)
	{
		EXPECT_TRUE(streamVarInt.putVarInt(i));
	}

	streamVarInt.rewind();
	for(int i=0;i<10000;i++)
	{
		EXPECT_TRUE(streamVarInt.getVarInt() == i);
	}
}

TEST(Stream_SaveString)
{
	FixedStream fixStream("abcdefg");
	EXPECT_TRUE(fixStream.size() == strlen("abcdefg"));

	fixStream.rewind();
	fixStream.putString("good");

	MXString str;
	fixStream.rewind();
	fixStream.getString(str);
	EXPECT_TRUE(str == "good");

	VarStream varStream("abcdefg");
	EXPECT_TRUE(varStream.size() == strlen("abcdefg"));

	varStream.rewind();
	varStream.putString("good");

	varStream.rewind();
	varStream.getString(str);
	EXPECT_TRUE(str == "good");
}

TEST(Stream_VarInt)
{
	VarStream stream;
	stream.putVarInt(63);
	EXPECT_TRUE(stream.size() == 1);
	stream.putVarInt(64);
	EXPECT_TRUE(stream.size() == 3);
	stream.putVarInt(8191);
	EXPECT_TRUE(stream.size() == 5);
	stream.putVarInt(8192);
	EXPECT_TRUE(stream.size() == 8);
	stream.putVarInt(128192);
	EXPECT_TRUE(stream.size() == 11);
	stream.putVarInt(3428192);
	EXPECT_TRUE(stream.size() == 15);
	stream.putVarInt(513428192);
	EXPECT_TRUE(stream.size() == 20);

	stream.rewind();
	EXPECT_TRUE(stream.getVarInt() == 63);
	EXPECT_TRUE(stream.getVarInt() == 64);
	EXPECT_TRUE(stream.getVarInt() == 8191);
	EXPECT_TRUE(stream.getVarInt() == 8192);
	EXPECT_TRUE(stream.getVarInt() == 128192);
	EXPECT_TRUE(stream.getVarInt() == 3428192);
	EXPECT_TRUE(stream.getVarInt() == 513428192);
}

TEST(Stream_Seek)
{
	FixedStream stream("abcde");
	EXPECT_TRUE(stream.position() == 0);

	stream.seek(2,SEEK_SET);
	EXPECT_TRUE(stream.position() == 2);
	EXPECT_TRUE(stream.getChar() == 'c');
	EXPECT_TRUE(stream.position() == 3);

	stream.seek(1,SEEK_CUR);
	EXPECT_TRUE(stream.position() == 4);
	EXPECT_TRUE(stream.getChar() == 'e');

	stream.seek(-4,SEEK_CUR);
	EXPECT_TRUE(stream.position() == 1);
	EXPECT_TRUE(stream.getChar() == 'b');

	stream.seek(0,SEEK_CUR);
	EXPECT_TRUE(stream.position() == 2);
	EXPECT_TRUE(stream.getChar() == 'c');

	stream.seek(0,SEEK_END);
	EXPECT_TRUE(stream.position() == 4);
	EXPECT_TRUE(stream.getChar() == 'e');

	EXPECT_FALSE(stream.seek(0,-1));
}
