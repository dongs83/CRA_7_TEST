#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "main.h"

using namespace std;

namespace DAYS {
	static const string MON = "monday";
	static const string TUE = "tuesday";
	static const string WED = "wednesday";
	static const string THU = "thursday";
	static const string FRI = "friday";
	static const string SAT = "saturday";
	static const string SUN = "sunday";

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

namespace GRADE {
	static const string GOLD = "GOLD";
	static const string SILVER = "SILVER";
	static const string NORMAL = "NORMAL";

	static const int SCORE_FOR_GOLD = 50;
	static const int SCORE_FOR_SILVER = 30;

	static const int NUM_GRADE_GOLD = 1;
	static const int NUM_GRADE_SILVER = 2;
	static const int NUM_GRADE_NORMAL = 0;
};

map<string, int> idList;
int idCount = 0;

int dat[100][100];
int points[100];
int grade[100];
string names[100];

int wednesday[100];
int weekend[100];

int main() {
	readFileAndMakeList("attendance_weekday_500.txt", 500);

	calculatePoint();
	calculateGrade();

	printResult();
}

void readFileAndMakeList(std::string filename, int numOfLine)
{
	ifstream inputFile{ filename };
	for (int i = 0; i < numOfLine; i++) {
		string name, day;
		inputFile >> name >> day;
		addDataToList(name, day);
	}
}

void calculatePoint()
{
	for (int i = 1; i <= idCount; i++) {
		if (dat[i][2] > 9) {
			points[i] += 10;
		}

		if (dat[i][5] + dat[i][6] > 9) {
			points[i] += 10;
		}

	}
}

void calculateGrade()
{
	for (int i = 1; i <= idCount; i++) {
		if (points[i] >= GRADE::SCORE_FOR_GOLD) {
			grade[i] = GRADE::NUM_GRADE_GOLD;
		}
		else if (points[i] >= GRADE::SCORE_FOR_SILVER) {
			grade[i] = GRADE::NUM_GRADE_SILVER;
		}
		else {
			grade[i] = GRADE::NUM_GRADE_NORMAL;
		}
	}
}

void printResult()
{
	for (int i = 1; i <= idCount; i++) {
		cout << "NAME : " << names[i] << ", ";
		cout << "POINT : " << points[i] << ", ";
		cout << "GRADE : ";

		if (grade[i] == GRADE::NUM_GRADE_GOLD) {
			cout << GRADE::GOLD << "\n";
		}
		else if (grade[i] == GRADE::NUM_GRADE_SILVER) {
			cout << GRADE::SILVER << "\n";
		}
		else {
			cout << GRADE::NORMAL << "\n";
		}
	}

	std::cout << "\n";
	std::cout << "Removed player\n";
	std::cout << "==============\n";

	for (int i = 1; i <= idCount; i++) {

		if (isNeededToBeRemoved(i)) {
			std::cout << names[i] << "\n";
		}
	}
}

bool isNeededToBeRemoved(int id)
{
	if (grade[id] == GRADE::NUM_GRADE_NORMAL &&
		wednesday[id] == 0 && weekend[id] == 0) {

		return true;
	}

	return  false;
}

void addDataToList(string name, string day) {

	if (idList.count(name) == 0) {
		idList.insert({ name, ++idCount });
		names[idCount] = name;
	}

	int idToAdd = idList[name];
	int pointToAdd = 0;
	int indexToAdd = 0;

	if (day == DAYS::MON) {
		indexToAdd = DAYS::IDX_MON;
		pointToAdd = DAYS::SCORE_MON;
	}
	if (day == DAYS::TUE) {
		indexToAdd = DAYS::IDX_TUE;
		pointToAdd = DAYS::SCORE_TUE;
	}
	if (day == DAYS::WED) {
		indexToAdd = DAYS::IDX_WED;
		pointToAdd = DAYS::SCORE_WED;
		wednesday[idToAdd] += 1;
	}
	if (day == DAYS::THU) {
		indexToAdd = DAYS::IDX_THU;
		pointToAdd = DAYS::SCORE_THU;
	}
	if (day == DAYS::FRI) {
		indexToAdd = DAYS::IDX_FRI;
		pointToAdd = DAYS::SCORE_FRI;
	}
	if (day == DAYS::SAT) {
		indexToAdd = DAYS::IDX_SAT;
		pointToAdd = DAYS::SCORE_SAT;
		weekend[idToAdd] += 1;
	}
	if (day == DAYS::SUN) {
		indexToAdd = DAYS::IDX_SUN;
		pointToAdd = DAYS::SCORE_SUN;
		weekend[idToAdd] += 1;
	}

	dat[idToAdd][indexToAdd] += 1;
	points[idToAdd] += pointToAdd;
}