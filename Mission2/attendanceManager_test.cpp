#include "gmock/gmock.h"
#include "attendanceManager.h"

class attendanceManagerTest : public ::testing::Test {
public:
	attendanceManager& mgr = attendanceManager::getInstance();
};

TEST_F(attendanceManagerTest, readInputFile) {
	mgr.readFileAndMakeList("attendance_weekday_500.txt", 500);
	EXPECT_EQ(mgr.players.size(), 19);
	EXPECT_EQ(mgr.idCount, 19);
}

TEST_F(attendanceManagerTest, playerWithWrongParam) {
	int cnt = mgr.players.size();
	mgr.addData("new_person", "WRONGDAY");
	EXPECT_EQ(cnt, cnt);
}

TEST_F(attendanceManagerTest, playerNeededToBeRemoved) {
	player p(1, "hello", DAYS::MON);
	EXPECT_EQ(mgr.isNeededToBeRemoved(&p), true);
}

TEST_F(attendanceManagerTest, playerNeededNotToBeRemoved) {
	player* p;

	for (int i = 0; i < 10; i++)
		mgr.addData("niceman", DAYS::SUN);
	mgr.applyBonus();

	p = mgr.players[0];

	EXPECT_EQ(mgr.isNeededToBeRemoved(p), false);
}

TEST_F(attendanceManagerTest, printNoException) {
	EXPECT_NO_THROW(mgr.printResults());
}
