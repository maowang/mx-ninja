#include "Test.h"
#include "geometry/Envelope.h"

USING_MX_NAMESPACE

TEST(Envelope_init)
{
	EnvelopeFloat envNull;
	EXPECT_TRUE(envNull.isNull());

	envNull.init(1,3,5,7);
	EXPECT_FALSE(envNull.isNull());
	EXPECT_TRUE(envNull.minX() == 1);
	EXPECT_TRUE(envNull.minY() == 3);
	EXPECT_TRUE(envNull.maxX() == 5);
	EXPECT_TRUE(envNull.maxY() == 7);

	envNull.init(5,7,1,3);
	EXPECT_FALSE(envNull.isNull());
	EXPECT_TRUE(envNull.minX() == 1);
	EXPECT_TRUE(envNull.minY() == 3);
	EXPECT_TRUE(envNull.maxX() == 5);
	EXPECT_TRUE(envNull.maxY() == 7);

	envNull.setToNull();
	EXPECT_TRUE(envNull.isNull());
	EXPECT_TRUE(envNull.minX() == 0);
	EXPECT_TRUE(envNull.minY() == 0);
	EXPECT_TRUE(envNull.maxX() == -1);
	EXPECT_TRUE(envNull.maxY() == -1);
}

TEST(Envelope_width_height_center)
{
	Coord2dDouble coord;
	EnvelopeInt env;
	env.center(coord);
	EXPECT_TRUE(coord.getX() == 0);
	EXPECT_TRUE(coord.getY() == 0);
	EXPECT_TRUE(env.width() == 0);
	EXPECT_TRUE(env.height() == 0);

	env.init(1,0,5,7);
	env.center(coord);
	EXPECT_TRUE(coord.getX() == 3);
	EXPECT_TRUE(coord.getY() == 3.5);
	EXPECT_TRUE(env.width() == 4);
	EXPECT_TRUE(env.height() == 7);
}

TEST(Envelope_expand)
{
	EnvelopeInt nulEnv;
	EXPECT_TRUE(nulEnv.isNull());
	nulEnv.expandToInclude(3,5);
	EXPECT_TRUE(nulEnv.minX() == 3);
	EXPECT_TRUE(nulEnv.minY() == 5);
	EXPECT_TRUE(nulEnv.maxX() == 3);
	EXPECT_TRUE(nulEnv.maxY() == 5);

	nulEnv.setToNull();
	EXPECT_TRUE(nulEnv.isNull());
	nulEnv.expandToInclude(EnvelopeInt(1,2,3,4));
	EXPECT_TRUE(nulEnv.minX() == 1);
	EXPECT_TRUE(nulEnv.minY() == 2);
	EXPECT_TRUE(nulEnv.maxX() == 3);
	EXPECT_TRUE(nulEnv.maxY() == 4);

	EnvelopeFloat env(0,1,6,9);
	env.expandToInclude(-3,0);
	EXPECT_TRUE(env.minX() == -3);
	EXPECT_TRUE(env.minY() == 0);
	EXPECT_TRUE(env.maxX() == 6);
	EXPECT_TRUE(env.maxY() == 9);

	env.expandToInclude(10,11);
	EXPECT_TRUE(env.minX() == -3);
	EXPECT_TRUE(env.minY() == 0);
	EXPECT_TRUE(env.maxX() == 10);
	EXPECT_TRUE(env.maxY() == 11);

	env.expandToInclude(5,15);
	EXPECT_TRUE(env.minX() == -3);
	EXPECT_TRUE(env.minY() == 0);
	EXPECT_TRUE(env.maxX() == 10);
	EXPECT_TRUE(env.maxY() == 15);

	env.expandToInclude(5,5);
	EXPECT_TRUE(env.minX() == -3);
	EXPECT_TRUE(env.minY() == 0);
	EXPECT_TRUE(env.maxX() == 10);
	EXPECT_TRUE(env.maxY() == 15);

	Coord2dFloat coord(15,-3);
	env.expandToInclude(coord);
	EXPECT_TRUE(env.minX() == -3);
	EXPECT_TRUE(env.minY() == -3);
	EXPECT_TRUE(env.maxX() == 15);
	EXPECT_TRUE(env.maxY() == 15);

	coord.setX(-5);
	coord.setY(20);	
	env.expandToInclude(coord);
	EXPECT_TRUE(env.minX() == -5);
	EXPECT_TRUE(env.minY() == -3);
	EXPECT_TRUE(env.maxX() == 15);
	EXPECT_TRUE(env.maxY() == 20);

	coord.setX(5);
	coord.setY(5);	
	env.expandToInclude(coord);
	EXPECT_TRUE(env.minX() == -5);
	EXPECT_TRUE(env.minY() == -3);
	EXPECT_TRUE(env.maxX() == 15);
	EXPECT_TRUE(env.maxY() == 20);

	EnvelopeFloat env2(0,0,5,5);
	env.expandToInclude(env2);
	EXPECT_TRUE(env.minX() == -5);
	EXPECT_TRUE(env.minY() == -3);
	EXPECT_TRUE(env.maxX() == 15);
	EXPECT_TRUE(env.maxY() == 20);

	env2.init(0,0,20,25);
	env.expandToInclude(env2);
	EXPECT_TRUE(env.minX() == -5);
	EXPECT_TRUE(env.minY() == -3);
	EXPECT_TRUE(env.maxX() == 20);
	EXPECT_TRUE(env.maxY() == 25)

	env2.init(-10,-5,20,25);
	env.expandToInclude(env2);
	EXPECT_TRUE(env.minX() == -10);
	EXPECT_TRUE(env.minY() == -5);
	EXPECT_TRUE(env.maxX() == 20);
	EXPECT_TRUE(env.maxY() == 25)

	env.expand(10,5);
	EXPECT_TRUE(env.minX() == -20);
	EXPECT_TRUE(env.minY() == -10);
	EXPECT_TRUE(env.maxX() == 30);
	EXPECT_TRUE(env.maxY() == 30)

	env.expand(0,20);
	EXPECT_TRUE(env.minX() == -20);
	EXPECT_TRUE(env.minY() == -30);
	EXPECT_TRUE(env.maxX() == 30);
	EXPECT_TRUE(env.maxY() == 50)
}

TEST(Envelope_contain_intersects)
{
	EnvelopeDouble env;
	EXPECT_FALSE(env.contains(0,0));

	env.init(1,5,10,15);
	EXPECT_FALSE(env.contains(0,0));
	EXPECT_FALSE(env.contains(1,0));
	EXPECT_FALSE(env.contains(0,5));
	EXPECT_FALSE(env.contains(20,0));
	EXPECT_FALSE(env.contains(20,10));
	EXPECT_FALSE(env.contains(20,15));

	EXPECT_TRUE(env.contains(1,5));
	EXPECT_TRUE(env.contains(1,10));
	EXPECT_TRUE(env.contains(1,15));

	EXPECT_TRUE(env.contains(1,5));
	EXPECT_TRUE(env.contains(5,5));
	EXPECT_TRUE(env.contains(10,5));
	EXPECT_TRUE(env.contains(5,15));
	EXPECT_TRUE(env.contains(10,15));

	Coord2dDouble coord(5,5);
	EXPECT_TRUE(env.contains(coord));
	coord.setX(10);
	coord.setY(10);
	EXPECT_TRUE(env.contains(coord));

	EnvelopeDouble env1(1,5,7,9);
	EnvelopeDouble env2(2,4,6,8);
	EnvelopeDouble env3(10,10,15,15);
	EXPECT_TRUE(env1.intersects(env1));
	EXPECT_TRUE(env1.intersects(env2));
	EXPECT_TRUE(env2.intersects(env2));
	EXPECT_FALSE(env1.intersects(env3));
	EXPECT_FALSE(env2.intersects(env3));
}
