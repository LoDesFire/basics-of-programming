#ifndef LW1_T3_NUMBER_H
#define LW1_T3_NUMBER_H

#include "Expression.h"

class Number : public Expression{
    double value;
public:
    explicit Number(double);
    double evaluate() override;
    double *getPtr();
};


#endif //LW1_T3_NUMBER_H
