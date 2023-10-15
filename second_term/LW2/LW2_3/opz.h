#ifndef OPZ_H
#define OPZ_H

#include <QString>
#include "stack.h"
#include "stack.cpp"
#include <cmath>

class OPZ
{
public:
    OPZ();
    static bool isOperator(char c);
    static bool isOperator(QCharRef c);
    static QString *exprToOPZ(QString str);
    static double calculate(QString str, bool &isError);
};

#endif // OPZ_H
