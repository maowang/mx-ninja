#ifndef _CHTTPCLIENT_H_
#define _CHTTPCLIENT_H_

#include "base/Base.h"

BEG_MX_NAMESPACE

class LIBMX_API CHttpClient
{
public:
	CHttpClient(void);
	~CHttpClient(void);

public:
	/**
	* @brief HTTP POST请求
	* @param strUrl 输入参数,请求的Url地址,如:http://www.baidu.com
	* @param strPost 输入参数,使用如下格式para1=val1¶2=val2&…
	* @param strResponse 输出参数,返回的内容
	* @return 返回是否Post成功
	*/
	int Post(const std::string & strUrl, const std::string & strPost, std::string & strResponse);

	/**
	* @brief HTTP GET请求
	* @param strUrl 输入参数,请求的Url地址,如:http://www.baidu.com
	* @param strResponse 输出参数,返回的内容
	* @return 返回是否Post成功
	*/
	int Get(const std::string & strUrl, std::string & strResponse);
};

END_MX_NAMESAPCE

#endif
