#include "Rand.h"
#include "Toolkit.h"

BEG_MX_NAMESPACE

Rand Rand::g_genRand((unsigned int)Toolkit::currentTime());

unsigned int Rand::randRange(unsigned int start, unsigned int end)
{
	return randUInt()%(end - start + 1) + start;
}

unsigned int Rand::genUInt( void )
{
	m_Seed[0] = (((m_Seed[0] & 0xFFFFFFFELU) << 24) & Max32BitLong)
		^ ((m_Seed[0] ^ ((m_Seed[0] << 7) & Max32BitLong)) >> 7);

	m_Seed[1] = (((m_Seed[1] & 0xFFFFFFF8LU) << 7) & Max32BitLong)
		^ ((m_Seed[1] ^ ((m_Seed[1] << 2) & Max32BitLong)) >> 22);

	m_Seed[2] = (((m_Seed[2] & 0xFFFFFFF0LU) << 11) & Max32BitLong)
		^ ((m_Seed[2] ^ ((m_Seed[2] << 9) & Max32BitLong)) >> 17);

	return (m_Seed[0] ^ m_Seed[1] ^ m_Seed[2]);
}

void Rand::Reset( const SeedType p_Seed /*= 0*/ )
{
	m_Seed[0] = (p_Seed ^ 0xFEA09B9DLU) & 0xFFFFFFFELU;
	m_Seed[0] ^= (((m_Seed[0] << 7) & Max32BitLong) ^ m_Seed[0]) >> 31;

	m_Seed[1] = (p_Seed ^ 0x9C129511LU) & 0xFFFFFFF8LU;
	m_Seed[1] ^= (((m_Seed[1] << 2) & Max32BitLong) ^ m_Seed[1]) >> 29;

	m_Seed[2] = (p_Seed ^ 0x2512CFB8LU) & 0xFFFFFFF0LU;
	m_Seed[2] ^= (((m_Seed[2] << 9) & Max32BitLong) ^ m_Seed[2]) >> 28;

	genUInt();
}

unsigned int Rand::randUInt( void )
{
	return g_genRand.genUInt();
}

END_MX_NAMESAPCE
