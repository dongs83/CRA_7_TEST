#include "gmock/gmock.h"
#include "grade.h"
using namespace testing;

TEST(GradeTest, GoldGradeName) {
    GoldGrade g;
    EXPECT_EQ(g.getName(), GOLD);
}

TEST(GradeTest, SilverGradeName) {
    SilverGrade s;
    EXPECT_EQ(s.getName(), SILVER);
}

TEST(GradeTest, NormalGradeName) {
    NormalGrade n;
    EXPECT_EQ(n.getName(), NORMAL);
}

TEST(GradeTest, MakeGoldGrade) {
    GradeFactory gf;
    auto grade = gf.createGrade(54);
    EXPECT_EQ(grade->getName(), GOLD);
}

TEST(GradeTest, MakeSilverGrade) {
    GradeFactory gf;
    auto grade = gf.createGrade(34);
    EXPECT_EQ(grade->getName(), SILVER);
}

TEST(GradeTest, MakeNormalGrade) {
    GradeFactory gf;
    auto grade = gf.createGrade(14);
    EXPECT_EQ(grade->getName(), NORMAL);
}
