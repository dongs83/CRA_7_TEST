#include "gmock/gmock.h"
#include "attendanceManager.h"

class attendanceManagerTest : public ::testing::Test {
public:
    attendanceManager& mgr = attendanceManager::getInstance();
};

TEST_F(attendanceManagerTest, readTestFile) {
    mgr.readFileAndMakeList("attendance_weekday_500.txt", 500);
    EXPECT_EQ(mgr.players.size(), 19);
    EXPECT_EQ(mgr.idCount, 19);
}

TEST_F(attendanceManagerTest, playerTest) {
    player p(1, "hello", DAYS::MON);
    EXPECT_EQ(mgr.isNeededToBeRemoved(&p), true);
}