#ifdef _DEBUG
#include "gmock/gmock.h"
int main(void) {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}
#else

#include <iostream>
#include "attendanceManager.h"
using namespace std;

attendanceManager& atManager = attendanceManager::getInstance();

int main() {
	atManager.readFileAndMakeList("attendance_weekday_500.txt", 500);
	atManager.applyBonus();
	atManager.printResults();
}
#endif