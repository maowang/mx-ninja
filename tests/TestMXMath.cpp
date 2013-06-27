#include "Test.h"
#include "base/MXMath.h"

USING_MX_NAMESPACE

TEST(MXMath_Round)
{
	double dval = 3.14;
	float  fval = 6.86;

	EXPECT_TRUE(MXMath::round(dval) == 3);
	EXPECT_TRUE(MXMath::round(fval) == 7);
	EXPECT_TRUE(MXMath::fastRound(dval) == 3);
	EXPECT_TRUE(MXMath::fastRound(fval) == 7);

	dval = -3.14;
	fval = -6.86;
	EXPECT_TRUE(MXMath::round(dval) == -3);
	EXPECT_TRUE(MXMath::round(fval) == -7);
	EXPECT_TRUE(MXMath::fastRound(dval) == -3);
	EXPECT_TRUE(MXMath::fastRound(fval) == -7);

	dval = 3.5;
	fval = 3.5;
	EXPECT_TRUE(MXMath::round(dval) == 4);
	EXPECT_TRUE(MXMath::round(fval) == 4);
	EXPECT_TRUE(MXMath::fastRound(dval) == 4);
	EXPECT_TRUE(MXMath::fastRound(fval) == 4);
}