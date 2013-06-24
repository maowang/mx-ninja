#include "Test.h"
#include "geometry/CoordinateArraySequence.h"
#include "geometry/CoordinateFixedSequence.h"

USING_MX_NAMESPACE

TEST(CoordinateArraySequence_resize)
{
	CoordArraySequenceInt array(1,12);
	EXPECT_TRUE(array.size() == 12);

	array.resize(25,123);
	EXPECT_TRUE(array.size() == 25);

	for(int i=12;i<25;i++)
	{
		EXPECT_TRUE(array.getValue(i,1) == 123);
	}

	CoordArraySequenceDouble iValue(2,3);
	iValue.setValue(0,1,0);
	iValue.setValue(0,2,1);
	iValue.setValue(1,1,2);
	iValue.setValue(1,2,3);
	iValue.setValue(2,1,4);
	iValue.setValue(2,2,5);

	for(int i=0;i<3;i++)
	{
		EXPECT_TRUE(iValue.getValue(i,1) == i * 2);
		EXPECT_TRUE(iValue.getValue(i,2) == (i * 2 + 1));
	}
}

TEST(CoordinateArraySequence_getset)
{
	CoordArraySequenceDouble dArray(3,2);
	dArray.setX(0,1);
	dArray.setY(0,2);
	dArray.setZ(0,3);

	dArray.setX(1,5);
	dArray.setY(1,6);
	dArray.setZ(1,7);

	EXPECT_TRUE(dArray.size() == 2);

	EXPECT_TRUE(dArray.getX(0) == 1);
	EXPECT_TRUE(dArray.getY(0) == 2);
	EXPECT_TRUE(dArray.getZ(0) == 3);
	EXPECT_TRUE(dArray.getX(1) == 5);
	EXPECT_TRUE(dArray.getY(1) == 6);
	EXPECT_TRUE(dArray.getZ(1) == 7);
}

TEST(CoordinateArraySequence_add)
{
	CoordArraySequenceFloat iArray;
	iArray.add(5);
	EXPECT_TRUE(iArray.getX(0) == 5);
	iArray.add(2);
	EXPECT_TRUE(iArray.getX(1) == 2);
	iArray.add(4);
	EXPECT_TRUE(iArray.getX(2) == 4);

	EXPECT_TRUE(iArray.size() == 3);

	CoordArraySequenceFloat iArray2d(2);
	iArray2d.add(1,3);
	iArray2d.add(5,9);
	EXPECT_TRUE(iArray2d.getX(0) == 1);
	EXPECT_TRUE(iArray2d.getY(0) == 3);
	EXPECT_TRUE(iArray2d.getX(1) == 5);
	EXPECT_TRUE(iArray2d.getY(1) == 9);

	EXPECT_TRUE(iArray2d.size() == 2);

	CoordArraySequenceFloat iArray3d(3,5);
	iArray3d.add(6,0,2);
	EXPECT_TRUE(iArray3d.size() == 6);
	EXPECT_TRUE(iArray3d.getX(5) == 6);
	EXPECT_TRUE(iArray3d.getY(5) == 0);
	EXPECT_TRUE(iArray3d.getZ(5) == 2);
}

TEST(CoordinateFixedSequence_setget)
{
	CoordFixedSequenceFloat<10> farray;
	for(int i=0;i<10;i++)
	{
		farray.setX(i,5.0);
		EXPECT_TRUE(farray.getX(i) == 5.0);
	}

	CoordFixedSequenceInt<3,2> iarray;
	EXPECT_TRUE(iarray.size() == 3);
	EXPECT_TRUE(iarray.dimension() == 2);

	iarray.setX(0,0);
	iarray.setY(0,1);
	iarray.setX(1,2);
	iarray.setY(1,3);
	iarray.setX(2,4);
	iarray.setY(2,5);

	for(int i=0;i<3;i++)
	{
		EXPECT_TRUE((iarray.getX(i) == i*2));
		EXPECT_TRUE((iarray.getY(i) == i*2+1));
	}

	const int sz = 100000;
	CoordFixedSequenceInt<sz,2>* seq = new CoordFixedSequenceInt<sz,2>();
	EXPECT_TRUE(seq->size() == sz);
	for(int i=0;i<sz;i++)
	{
		seq->setX(i,4);
		EXPECT_TRUE(seq->getX(i) == 4);
		seq->setY(i,6);
		EXPECT_TRUE(seq->getY(i) == 6);
	}
	SAVE_DELETE(seq);
}