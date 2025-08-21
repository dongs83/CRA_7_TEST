#include "gmock/gmock.h"
#include "grade.h"
using namespace testing;

TEST(gradeTest, goldGradeName) {
	goldGrade g;
	EXPECT_EQ(g.getName(), GOLD);
}

TEST(gradeTest, silverGradeName) {
	silverGrade s;
	EXPECT_EQ(s.getName(), SILVER);
}

TEST(gradeTest, normalGradeName) {
	normalGrade n;
	EXPECT_EQ(n.getName(), NORMAL);
}

TEST(gradeTest, makeGoldGrade) {
	gradeFactory gf;
	auto grade = gf.createGrade(54);
	EXPECT_EQ(grade->getName(), GOLD);
}

TEST(gradeTest, makeSilverGrade) {
	gradeFactory gf;
	auto grade = gf.createGrade(34);
	EXPECT_EQ(grade->getName(), SILVER);
}

TEST(gradeTest, makeNormalGrade) {
	gradeFactory gf;
	auto grade = gf.createGrade(14);
	EXPECT_EQ(grade->getName(), NORMAL);
}

TEST(gradeTest, makePassGrade) {
	gradeFactory gf;

	EXPECT_EQ(gf.isFailedGrade(64), false);
}

TEST(gradeTest, makeFailGrade) {
	gradeFactory gf;

	EXPECT_EQ(gf.isFailedGrade(14), true);
}
