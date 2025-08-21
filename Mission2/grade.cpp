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
	std::string getName() const override {
		return GOLD;
	}
};
class SilverGrade : public Grade {
public:
	std::string getName() const override {
		return SILVER;
	}
};
class NormalGrade : public Grade {
public:
	std::string getName() const override {
		return NORMAL;
	}
};

//Design pattern : simple factory
class GradeFactory {
public:
	static std::unique_ptr<Grade> createGrade(int score) {
		if (score >= SCORE_FOR_GOLD) return std::make_unique<GoldGrade>();
		if (score >= SCORE_FOR_SILVER) return std::make_unique<SilverGrade>();
		return std::make_unique<NormalGrade>();
	}
	static bool isFailedGrade(int score) {
		if (score < SCORE_FOR_SILVER)
			return true;

		return false;
	}
};
