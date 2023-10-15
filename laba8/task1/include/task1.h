#pragma once

#include "inputChecker.h"

struct flight {
    int number, hours, minutes;
    char *typeOfPlane, *destination, *timeOfDeparture;
};

#include "../source/sortStr.cpp"
#include "../source/changeStr.cpp"
#include "../source/inputStr.cpp"
#include "../source/printStr.cpp"
#include "../source/searchStr.cpp"
#include "../source/resizeStr.cpp"
#include "../source/deleteStr.cpp"
#include "../source/initStr.cpp"