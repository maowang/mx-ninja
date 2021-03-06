#include "Test.h"
#include "geometry/Coordinate.h"
#include "base/VarSequence.h"
#include "base/FixedSequence.h"

USING_MX_NAMESPACE

TEST(CoordinateArraySequence_resize)
{
	VarSequenceInt array(1,12);
	EXPECT_TRUE(array.size() == 12);

	array.resize(25,123);
	EXPECT_TRUE(array.size() == 25);

	for(int i=12;i<25;i++)
	{
		EXPECT_TRUE(array.getValue(i,1) == 123);
	}

	VarSequenceDouble iValue(2,3);
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
	VarSequenceDouble dArray(3,2);
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
	VarSequenceFloat iArray;
	iArray.add(5);
	EXPECT_TRUE(iArray.getX(0) == 5);
	iArray.add(2);
	EXPECT_TRUE(iArray.getX(1) == 2);
	iArray.add(4);
	EXPECT_TRUE(iArray.getX(2) == 4);

	EXPECT_TRUE(iArray.size() == 3);

	VarSequenceFloat iArray2d(2);
	iArray2d.add(1,3);
	iArray2d.add(5,9);
	EXPECT_TRUE(iArray2d.getX(0) == 1);
	EXPECT_TRUE(iArray2d.getY(0) == 3);
	EXPECT_TRUE(iArray2d.getX(1) == 5);
	EXPECT_TRUE(iArray2d.getY(1) == 9);

	EXPECT_TRUE(iArray2d.size() == 2);

	VarSequenceFloat iArray3d(3,5);
	iArray3d.add(6,0,2);
	EXPECT_TRUE(iArray3d.size() == 6);
	EXPECT_TRUE(iArray3d.getX(5) == 6);
	EXPECT_TRUE(iArray3d.getY(5) == 0);
	EXPECT_TRUE(iArray3d.getZ(5) == 2);
}

TEST(CoordinateFixedSequence_setget)
{
	FixedSequenceFloat<10> farray;
	for(int i=0;i<10;i++)
	{
		farray.setX(i,5.0);
		EXPECT_TRUE(farray.getX(i) == 5.0);
	}

	FixedSequenceInt<3,2> iarray;
	EXPECT_TRUE(iarray.size() == 3);

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
	FixedSequenceInt<sz,2>* seq = new FixedSequenceInt<sz,2>();
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

TEST(Coordinate_2d3d)
{
	int SIZE_OF_INT = sizeof(int);
	int SIZE_OF_FLOAT = sizeof(float);
	int SIZE_OF_DOUBLE = sizeof(double);

	int SIZE_OF_EXTRA = sizeof(void*);
	Coord2dDouble *cc = new Coord2dDouble;
	int test  =sizeof(cc);

	EXPECT_TRUE(sizeof(Coord2dInt) == SIZE_OF_INT*2 +SIZE_OF_EXTRA);
	EXPECT_TRUE(sizeof(Coord2dFloat) == SIZE_OF_FLOAT*2 +SIZE_OF_EXTRA);

	EXPECT_TRUE(sizeof(Coord3dInt) == SIZE_OF_INT*3 +SIZE_OF_EXTRA);
	EXPECT_TRUE(sizeof(Coord3dFloat) == SIZE_OF_FLOAT*3 +SIZE_OF_EXTRA);

	Coord2dFloat zero;
	EXPECT_TRUE(zero.getX() == 0);
	EXPECT_TRUE(zero.getY() == 0);

	Coord2dFloat coord2d(4,6);
	EXPECT_TRUE(coord2d.getX() == 4);
	EXPECT_TRUE(coord2d.getY() == 6);

	coord2d.setX(1);
	coord2d.setY(3);

	EXPECT_TRUE(coord2d.getX() == 1);
	EXPECT_TRUE(coord2d.getY() == 3);

	Coord3dFloat zero3d;
	EXPECT_TRUE(zero3d.getX() == 0);
	EXPECT_TRUE(zero3d.getY() == 0);
	EXPECT_TRUE(zero3d.getZ() == 0);

	Coord3dFloat coord3d(4,6,8);
	EXPECT_TRUE(coord3d.getX() == 4);
	EXPECT_TRUE(coord3d.getY() == 6);
	EXPECT_TRUE(coord3d.getZ() == 8);

	coord3d.setX(1);
	coord3d.setY(3);
	coord3d.setZ(5);
	EXPECT_TRUE(coord3d.getX() == 1);
	EXPECT_TRUE(coord3d.getY() == 3);
	EXPECT_TRUE(coord3d.getZ() == 5);
}

TEST(FixedSequence_set_get)
{
	FixedSequenceAlloc<int,3> seq(3);

	seq.setX(0,1);
	seq.setY(0,2);
	seq.setZ(0,3);

	seq.setX(1,4);
	seq.setY(1,5);
	seq.setZ(1,6);

	seq.setX(2,7);
	seq.setY(2,8);
	seq.setZ(2,9);

	EXPECT_TRUE(seq.getX(0) == 1);
	EXPECT_TRUE(seq.getY(0) == 2);
	EXPECT_TRUE(seq.getZ(0) == 3);

	EXPECT_TRUE(seq.getX(1) == 4);
	EXPECT_TRUE(seq.getY(1) == 5);
	EXPECT_TRUE(seq.getZ(1) == 6);

	EXPECT_TRUE(seq.getX(2) == 7);
	EXPECT_TRUE(seq.getY(2) == 8);
	EXPECT_TRUE(seq.getZ(2) == 9);
}