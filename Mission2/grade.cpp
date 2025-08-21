#pragma once
#include <iostream>
#include "grade.h"

std::string GoldGrade::getName() const {
	return GOLD;
}

std::string SilverGrade::getName() const {
	return SILVER;
}

std::string NormalGrade::getName() const {
	return NORMAL;
}

std::unique_ptr<Grade> GradeFactory::createGrade(int score) {
	if (score >= SCORE_FOR_GOLD) return std::make_unique<GoldGrade>();
	if (score >= SCORE_FOR_SILVER) return std::make_unique<SilverGrade>();
	return std::make_unique<NormalGrade>();
}

bool GradeFactory::isFailedGrade(int score) {
	if (score < SCORE_FOR_SILVER)
		return true;

	return false;
}