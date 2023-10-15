#include "BinaryOperator.h"


BinaryOperator::BinaryOperator(Expression *left, char oper, Expression *right) : _left(left), _operator(oper), _right(right)
{}

double BinaryOperator::evaluate() {
    switch(_operator) {
        case '+':
            return _left->evaluate() + _right->evaluate();
        case '-':
            return _left->evaluate() - _right->evaluate();
        case '*':
            return _left->evaluate() * _right->evaluate();
        case '/':
            return _left->evaluate() / _right->evaluate();
    }
}

BinaryOperator::~BinaryOperator() {
    delete _left;
    delete _right;
}