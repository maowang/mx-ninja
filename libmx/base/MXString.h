#ifndef _MX_STRING_H
#define _MX_STRING_H

#include "base/Base.h"

BEG_MX_NAMESPACE
class LIBMX_API MXString
{
public:
    MXString();
    MXString(const char* str);
    MXString(const std::string& str);
    MXString(const MXString& str);

    virtual ~MXString();

    bool format(const char* format, ...);

	bool create_format(unsigned int size,const char* format, ...);

	const char* data() const
	{
		return _string.c_str();
	}

	unsigned int length() const
	{
		return _string.length();
	}

	void lower()
	{
		std::transform(
			_string.begin(),
			_string.end(),
			_string.begin(),
			tolower);
	}

	void upper() 
	{
		std::transform(
			_string.begin(),
			_string.end(),
			_string.begin(),
			toupper);
	}

	void replace(const MXString& src,const MXString& to);
	void split(std::vector<MXString>& tokens,const MXString& delimiters);
    bool compare(const char * str) const;
	bool compare_nocase(const char * str) const;
	bool compare_nocase(const MXString& other) const;

	const MXString& operator= (const MXString& other);
	bool operator== (const MXString& other);
	bool operator!= (const MXString& other);
private:
    bool _format(unsigned int size,const char* format, va_list ap);
	bool _formatsmall(const char* format, va_list ap);
    std::string _string;
};

END_MX_NAMESAPCE

#endif
