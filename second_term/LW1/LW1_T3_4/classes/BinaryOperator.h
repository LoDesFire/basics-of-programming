#ifndef LW1_T3_BINARYOPERATOR_H
#define LW1_T3_BINARYOPERATOR_H

#include "Expression.h"
#include "Number.h"

class BinaryOperator : public Expression{
    Expression *_left, *_right;
    char _operator;
public:
    BinaryOperator(Expression *left, char oper, Expression *right);
    ~BinaryOperator() override;
    double evaluate() override;
};


#endif //LW1_T3_BINARYOPERATOR_H
