#pragma once
#include <iostream>

#define interface struct

namespace {
	static const std::string GOLD = "GOLD";
	static const std::string SILVER = "SILVER";
	static const std::string NORMAL = "NORMAL";

	static const int SCORE_FOR_GOLD = 50;
	static const int SCORE_FOR_SILVER = 30;
};

class Grade {
public:
	virtual std::string getName() const = 0;
};

class GoldGrade : public Grade {
public:
	std::string getName() const override;
};

class SilverGrade : public Grade {
public:
	std::string getName() const override;
};

class NormalGrade : public Grade {
public:
	std::string getName() const override;
};

class GradeFactory {
public:
	std::unique_ptr<Grade> createGrade(int score);
	bool isFailedGrade(int score);
};
