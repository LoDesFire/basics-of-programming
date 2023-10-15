#pragma once
#include <cstdio>
#include <fstream>
#include <clocale>
#include "pattern.h"
#include "inputChecker.h"

struct trip {
    int number, b_hours, b_minutes, e_hours, e_minutes;
    char *typeOfPlane, *destination, *b_time, *e_time;
};

void action(int, trip *&, int &, std::ifstream &, std::ofstream &);

#include "../source/inputStr.cpp"
#include "../source/inputStrF.cpp"
#include "../source/printStr.cpp"
#include "../source/printStrF.cpp"
#include "../source/changeStr.cpp"
#include "../source/searchStr.cpp"
#include "../source/resizeStr.cpp"
#include "../source/deleteStr.cpp"
#include "../source/initStrF.cpp"