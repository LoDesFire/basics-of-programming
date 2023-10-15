#ifndef LW1_T3_EXPRESSION_H
#define LW1_T3_EXPRESSION_H


class Expression {
public:
    virtual double evaluate() = 0;
    virtual ~Expression() = default;
};

#endif //LW1_T3_EXPRESSION_H
