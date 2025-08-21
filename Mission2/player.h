#pragma once
#include <iostream>

class player {
public:
    int id;
    std::string name;
    std::string day;
    int totalPoint;
    int wedCount;
    int weekendCount;
    int dayCount[7] = { 0, };

    player(int _id, std::string _name, std::string _day) {
        id = _id;
        name = _name;
        day = _day;

        totalPoint = 0;
        wedCount = 0;
        weekendCount = 0;
    }
};