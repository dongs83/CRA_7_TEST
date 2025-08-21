#pragma once
#include <iostream>
#include "grade.h"

std::string goldGrade::getName() const {
	return GOLD;
}

std::string silverGrade::getName() const {
	return SILVER;
}

std::string normalGrade::getName() const {
	return NORMAL;
}

std::unique_ptr<grade> gradeFactory::createGrade(int score) {
	if (score >= SCORE_FOR_GOLD) return std::make_unique<goldGrade>();
	if (score >= SCORE_FOR_SILVER) return std::make_unique<silverGrade>();
	return std::make_unique<normalGrade>();
}

bool gradeFactory::isFailedGrade(int score) {
	if (score < SCORE_FOR_SILVER)
		return true;

	return false;
}