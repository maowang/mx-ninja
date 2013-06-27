#include "Test.h"
#include "base/MXString.h"

USING_MX_NAMESPACE

TEST(MXString_format)
{
	MXString straa("aa");
	EXPECT_TRUE(straa == "aa");

	MXString strbb(std::string("bb"));
	EXPECT_TRUE(strbb == "bb");

	MXString strbb2(strbb);
	EXPECT_TRUE(strbb2 == "bb");

	MXString strcc;
	strcc.format("%s","cc");
	EXPECT_TRUE(strcc == "cc");
	strcc.format("%.1f",0.34);
	EXPECT_TRUE(strcc == "0.3");

	MXString strdd;
	strdd.create_format(100,"%s","dd");
	EXPECT_TRUE(strdd == "dd");

	strdd = "dd2";
	EXPECT_TRUE(strdd == "dd2");
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

TEST(MXString_split)
{
	MXString str1 = "1,2,3";
	std::vector<MXString> tokens;
	str1.split(tokens,",");
	EXPECT_TRUE(tokens.size()==3);
	EXPECT_TRUE(tokens[0]=="1");
	EXPECT_TRUE(tokens[1]=="2");
	EXPECT_TRUE(tokens[2]=="3");

	MXString str2 = "1,2,,3";
	str2.split(tokens,",");
	EXPECT_TRUE(tokens.size()==3);
	EXPECT_TRUE(tokens[0]=="1");
	EXPECT_TRUE(tokens[1]=="2");
	EXPECT_TRUE(tokens[2]=="3");

	MXString str3 = "|||1|||2|||3|||";
	str3.split(tokens,"|||");
	EXPECT_TRUE(tokens.size()==3);
	EXPECT_TRUE(tokens[0]=="1");
	EXPECT_TRUE(tokens[1]=="2");
	EXPECT_TRUE(tokens[2]=="3");
}