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

class grade {
public:
	virtual std::string getName() const = 0;
};

class goldGrade : public grade {
public:
	std::string getName() const override;
};

class silverGrade : public grade {
public:
	std::string getName() const override;
};

class normalGrade : public grade {
public:
	std::string getName() const override;
};

class gradeFactory {
public:
	std::unique_ptr<grade> createGrade(int score);
	bool isFailedGrade(int score);
};
