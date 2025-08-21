#include "gmock/gmock.h"
#include "grade.cpp"
using namespace testing;

TEST(GradeTest, GoldGradeName) {
    GoldGrade g;
    EXPECT_EQ(g.getName(), "Gold");
}

TEST(GradeTest, SilverGradeName) {
    SilverGrade s;
    EXPECT_EQ(s.getName(), "Silver");
}

TEST(GradeTest, NormalGradeName) {
    NormalGrade n;
    EXPECT_EQ(n.getName(), "Normal");
}

TEST(GradeTest, MakeGoldGrade) {
    auto grade = GradeFactory::createGrade(54);
    EXPECT_EQ(grade->getName(), "Gold");
}

TEST(GradeTest, MakeSilverGrade) {
    auto grade = GradeFactory::createGrade(34);
    EXPECT_EQ(grade->getName(), "Silver");
}

TEST(GradeTest, MakeNormalGrade) {
    auto grade = GradeFactory::createGrade(14);
    EXPECT_EQ(grade->getName(), "Normal");
}
