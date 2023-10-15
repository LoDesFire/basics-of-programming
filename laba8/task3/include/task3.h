#pragma once
#include <cstdio>
#include <fstream>
#include <clocale>
#include "pattern.h"
#include "inputChecker.h"

class trip {
public:
    int b_hours, b_minutes, e_hours, e_minutes;
    char typeOfPlane[101], destination[101], b_time[6], e_time[6];
    union {
        int number;
        struct{
            unsigned b0:1;
            unsigned b1:1;
            unsigned b2:1;
            unsigned b3:1;
        } byte;
    } un;
};

void action(int, trip *&, int &, FILE *f);

#include "../source/inputStr.cpp"
#include "../source/inputStrF.cpp"
#include "../source/printStr.cpp"
#include "../source/changeStr.cpp"
#include "../source/searchStr.cpp"
#include "../source/resizeStr.cpp"
#include "../source/deleteStr.cpp"
#include "../source/initStrF.cpp"
#include "../source/sortStr.cpp"