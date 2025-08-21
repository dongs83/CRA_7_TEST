#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "player.cpp"
#include "grade.cpp"

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
private:
    attendanceManager() {}
	std::vector<player*> players;
	int idCount = 0;
public:
    attendanceManager(const attendanceManager&) = delete;
    attendanceManager& operator=(const attendanceManager&) = delete;

    static attendanceManager& getInstance() {
        static attendanceManager instance;
        return instance;
    }

	void readFileAndMakeList(std::string filename, int numOfLine)
	{
		std::ifstream inputFile{ filename };
		for (int i = 0; i < numOfLine; i++) {
			std::string name, day;
			inputFile >> name >> day;
			addData(name, day);
		}
	}

    void addData(std::string name, std::string day) {
		int isFound = 0;
		player *curPlayer = nullptr;

		for (player *p : players)
		{
			if (p->name == name) {
				isFound = 1;
				curPlayer = p;
			}
		}

		if (isFound == 0) {
			curPlayer = new player(++idCount, name, day);
			players.push_back(curPlayer);
		}

		int pointToAdd = 0;
		int indexToAdd = 0;

		if (day == DAYS::MON) {
			indexToAdd = DAYS::IDX_MON;
			pointToAdd = DAYS::SCORE_MON;
		}
		else if (day == DAYS::TUE) {
			indexToAdd = DAYS::IDX_TUE;
			pointToAdd = DAYS::SCORE_TUE;
		}
		else if (day == DAYS::WED) {
			indexToAdd = DAYS::IDX_WED;
			pointToAdd = DAYS::SCORE_WED;
			curPlayer->wedCount++;
		}
		else if (day == DAYS::THU) {
			indexToAdd = DAYS::IDX_THU;
			pointToAdd = DAYS::SCORE_THU;
		}
		else if (day == DAYS::FRI) {
			indexToAdd = DAYS::IDX_FRI;
			pointToAdd = DAYS::SCORE_FRI;
		}
		else if (day == DAYS::SAT) {
			indexToAdd = DAYS::IDX_SAT;
			pointToAdd = DAYS::SCORE_SAT;
			curPlayer->weekendCount++;
		}
		else if (day == DAYS::SUN) {
			indexToAdd = DAYS::IDX_SUN;
			pointToAdd = DAYS::SCORE_SUN;
			curPlayer->weekendCount++;
		}
		else {
			std::cout << "Wrong parameter : " << day << std::endl;
			return;
		}

		curPlayer->dayCount[indexToAdd]++;
		curPlayer->totalScore += pointToAdd;
    }

    void applyBonus() {
        for (auto& p : players) {
            if (p->wedCount >= 10) p->totalScore += 10;
            if (p->weekendCount >= 10) p->totalScore += 10;
        }
    }
	
	void printResults() {

		for (auto& p : players) {
			auto grade = GradeFactory::createGrade(p->totalScore);

			std::cout << "NAME : " << p->name << ", ";
			std::cout << "POINT : " << p->totalScore << ", ";
			std::cout << "GRADE : " << grade->getName() << "\n";
		}

		std::cout << "\n";
		std::cout << "Removed player\n";
		std::cout << "==============\n";

		for (auto& p : players) {

			if (isNeededToBeRemoved(p)) {
				std::cout << p->name << "\n";
			}
		}
	}

	bool isNeededToBeRemoved(player *p)
	{
		if (GradeFactory::isFailedGrade(p->totalScore)  &&
			p->wedCount == 0 && p->weekendCount == 0) {

			return true;
		}

		return  false;
	}
};