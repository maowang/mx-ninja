#include "Test.h"
#include "base/CHttpClient.h"

USING_MX_NAMESPACE

TEST(TestHttpClient_Get)
{
	std::string result;
	CHttpClient client;
	client.Get("http://www.baidu.com/",result);
	EXPECT_TRUE(result.size() > 0);
}

TEST(TestHttpClient_Post)
{
	std::string result;
	CHttpClient client;
	client.Post("http://www.baidu.com/","abc",result);
	EXPECT_TRUE(result.size() > 0);
}
