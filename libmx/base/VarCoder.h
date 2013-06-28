#ifndef _VAR_CODER_H_
#define _VAR_CODER_H_

#include "base/Base.h"
#include "base/Stream.h"

BEG_MX_NAMESPACE

#define DECODE_ZIG_ZAG(n) (((n) >> 1) ^ -((n) & 1))
#define ENCODE_ZIG_ZAG(n) ((n)  << 1) ^ ((n) >> 31)

class LIBMX_API VarCoder
{
public:
	static int decode(Stream& in) {
		unsigned char b=0;
		int result=0;
		b = in.getChar();
		result  = (b & 0x7F)      ; if (!(b & 0x80)) goto done;
		b = in.getChar();
		result |= (b & 0x7F) <<  7; if (!(b & 0x80)) goto done;
		b = in.getChar();
		result |= (b & 0x7F) << 14; if (!(b & 0x80)) goto done;
		b = in.getChar();
		result |= (b & 0x7F) << 21; if (!(b & 0x80)) goto done;
		b = in.getChar();
		result |=  b         << 28; if (!(b & 0x80)) goto done;		
done:
		result = DECODE_ZIG_ZAG(result);
		return result;
	}

	static void encode(unsigned char* buf,Stream& out,int val)
	{
		val = ENCODE_ZIG_ZAG(val);

		int idx = 0;
		while (true) {
			if ((val & ~0x7F) == 0) {
				buf[idx++] = val;
				break;
			} else {
				buf[idx++] = (val & 0x7F) | 0x80;
				val >>= 7;
			}
		}

		out.writeBytes(buf,idx);
	}
};

END_MX_NAMESPACE

#endif


