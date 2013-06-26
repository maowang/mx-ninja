#include "base/MXString.h"

BEG_MX_NAMESPACE

MXString::MXString(){}

MXString::MXString(const char * str) 
	: _string(str)
{}

MXString::MXString(const std::string& str)
    :_string(str)
{}

MXString::MXString(const MXString& str)
    :_string(str.data())
{}

MXString::~MXString(){}

bool MXString::_formatsmall(const char* format, va_list ap)
{
	bool bRet = false;
	const int smallsize = 256;
	char pBuf[smallsize];
	if (pBuf != NULL)
	{
		vsnprintf(pBuf, smallsize, format, ap);
		_string = pBuf;
		bRet = true;
	}
	return bRet;
}

bool MXString::_format(unsigned int max_size,const char* format, va_list ap)
{
	if(max_size > 32 * 1024)return false;

    bool bRet = false;
    char* pBuf = (char*)malloc(max_size);
    if (pBuf != NULL)
    {
        vsnprintf(pBuf, max_size, format, ap);
        _string = pBuf;
        free(pBuf);
        bRet = true;
    }
    return bRet;
}

bool MXString::format(const char* format, ...)
{
    bool bRet = false;
    _string.clear();

    va_list ap;
    va_start(ap, format);

    bRet = _formatsmall(format, ap);

    va_end(ap);

    return bRet;
}

bool MXString::create_format(unsigned int size,const char* format, ...)
{
	bool bRet = false;
	_string.clear();

	va_list ap;
	va_start(ap, format);

	bRet = _format(size,format, ap);

	va_end(ap);

	return bRet;
}

bool MXString::compare(const char * str) const
{
    return strcmp(data(), str) == 0;
}

bool MXString::compare_nocase(const char * str) const
{
	return stricmp(data(), str) == 0;
}

bool MXString::compare_nocase(const MXString& other) const
{
	if(length() != other.length())	return false;
	return stricmp(data(),other.data()) == 0;
}

const MXString& MXString::operator= (const MXString& other)
{
	if(&other != this)
	{
		_string = other._string;
	}
	return *this;
}

bool MXString::operator== (const MXString& other)
{
	if(length() != other.length())	return false;
	return strcmp(data(),other.data()) == 0;
}

bool MXString::operator!= (const MXString& other)
{
	return !(*this == other);
}

void MXString::split( std::vector<MXString>& tokens,const MXString& delimiters )
{
	std::string::size_type lastPos = 0;
	std::string::size_type pos = _string.find_first_of(delimiters.data(), lastPos);

	while (std::string::npos != pos || std::string::npos != lastPos)
	{
		tokens.push_back(_string.substr(lastPos, pos - lastPos));

		lastPos = _string.find_first_not_of(delimiters.data(), pos);

		pos = _string.find_first_of(delimiters.data(), lastPos);
	}
}

int MXString::find( const MXString& str,unsigned offset /*= 0*/ )
{
	std::string::size_type pos = _string.find_first_of(str.data(), 0);
	if(pos == std::string::npos)
	{
			return -1;
	}
	
	return pos;
}

void MXString::replace( const MXString& src,const MXString& to )
{
	int lastPos = 0;
	int pos = find(src,lastPos);

	while (-1 != pos || pos != lastPos)
	{
		_string.replace(pos,src.length(),to.data());

		lastPos = pos + to.length();

		pos = find(src,lastPos);
	}
}

END_MX_NAMESAPCE