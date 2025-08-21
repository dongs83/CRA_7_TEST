#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "player.h"
#include "grade.h"

namespace DAYS {
	static const std::string MON = "monday";
	static const std::string TUE = "tuesday";
	static const std::string WED = "wednesday";
	static const std::string THU = "thursday";
	static const std::string FRI = "friday";
	static const std::string SAT = "saturday";
	static const std::string SUN = "sunday";

	static const int IDX_MON = 0;
	static const int IDX_TUE = 1;
	static const int IDX_WED = 2;
	static const int IDX_THU = 3;
	static const int IDX_FRI = 4;
	static const int IDX_SAT = 5;
	static const int IDX_SUN = 6;

	static const int SCORE_MON = 1;
	static const int SCORE_TUE = 1;
	static const int SCORE_WED = 3;
	static const int SCORE_THU = 1;
	static const int SCORE_FRI = 1;
	static const int SCORE_SAT = 2;
	static const int SCORE_SUN = 2;
};

class attendanceManager {
public:
	attendanceManager() {}
	std::vector<player*> players;
	int idCount = 0;

	attendanceManager(const attendanceManager&) = delete;
	attendanceManager& operator=(const attendanceManager&) = delete;

	static attendanceManager& getInstance() {
		static attendanceManager instance;
		return instance;
	}

	void readFileAndMakeList(std::string filename, int numOfLine);

	void addData(std::string name, std::string day);

	void applyBonus();

	void printResults();

	bool isNeededToBeRemoved(player* p);
};