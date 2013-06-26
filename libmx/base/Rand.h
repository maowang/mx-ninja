#ifndef _RAND_H_
#define _RAND_H_

#include "base/Base.h"

BEG_MX_NAMESPACE

class LIBMX_API Rand
{
public:
	//Returns an unsigned integer from 0..RandomMax
	//0~RandMax unsigned int 随机数
	static unsigned int randUInt(void);

	//Returns a double in [0.0, 1.0]
	//返回0.0~1.0之间的双精度浮点
	static double randDouble(void)
	{
		return static_cast<double>(randUInt())
			/ (static_cast<double>(RandomMax) );
	}

	// 返回[start,end]之间的整数
	static unsigned int randRange(unsigned int start, unsigned int end);
private:
	typedef unsigned long SeedType;
	SeedType m_Seed[3];
	static const SeedType Max32BitLong = 0xFFFFFFFFLU;
	static const SeedType RandomMax = Max32BitLong;

	Rand(const SeedType p_Seed = 0)
	{
		Reset(p_Seed);
	}

	void Reset(const SeedType p_Seed = 0);

	unsigned int genUInt(void);

	static Rand g_genRand;
};

END_MX_NAMESAPCE

#endif
