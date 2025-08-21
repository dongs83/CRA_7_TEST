//#ifdef _DEBUG
#if 0
#include "gmock/gmock.h"
int main(void) {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}
#else

#include <iostream>
#include "main.h"
#include "attendanceManager.cpp"
using namespace std;

attendanceManager& mgr = attendanceManager::getInstance();

int main() {
	mgr.readFileAndMakeList("attendance_weekday_500.txt", 500);
	mgr.applyBonus();
	mgr.printResults();
}
#endif