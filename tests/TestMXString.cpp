#include "Test.h"
#include "base/MXString.h"

USING_MX_NAMESPACE

TEST(MXString_format)
{
	MXString straa("aa");
	printf("%s\n",straa.data());

	MXString strbb(std::string("bb"));
	printf("%s\n",strbb.data());

	MXString strbb2(strbb);
	printf("%s\n",strbb2.data());

	MXString strcc;
	strcc.format("%s","cc");
	printf("%s\n",strcc.data());
	strcc.format("%.1f",0.34);
	printf("%s\n",strcc.data());

	MXString strdd;
	strdd.create_format(100,"%s","ddddddddddddddd");
	printf("%s\n",strdd.data());
}

TEST(MXString_lower_upper)
{
	MXString str = "test mxstring";
	str.upper();
	EXPECT_TRUE(str == "TEST MXSTRING");

	MXString str2 = "TEST MXSTRING";
	str2.lower();
	EXPECT_TRUE(str2 == "test mxstring");
}

TEST(MXString_replace)
{
	MXString str = "Hello World!";
	str.replace("World","my boy");

	EXPECT_TRUE(str == "Hello my boy!");
}

TEST(MXString_compare)
{
	MXString str1 = "Hello World!";
	MXString str2 = "HELLO world!";

	EXPECT_TRUE(str1 != str2);

	EXPECT_TRUE(!str1.compare(str2.data()));
	EXPECT_TRUE(str1.compare_nocase(str2));
	EXPECT_TRUE(str1.compare_nocase(str2.data()));
}
