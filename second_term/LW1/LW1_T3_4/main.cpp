#include <iostream>

#include "classes/BinaryOperator.h"
#include "classes/Number.h"

using namespace std;

bool check_equals(Expression const* left, Expression const* right) {
    return *(void **)left == *(void **)right;
}

int main() {
    Expression *sube = new BinaryOperator(new Number(4.5), '*', new Number(5));
    Expression *expr = new BinaryOperator(new Number(3), '+', sube);
    Expression *num1 = new Number(1212);
    Expression *num2 = new Number(12554);
    cout << expr->evaluate() << "\n";
    cout << (check_equals(expr, num1) ? "Yes\n" : "No\n");
    cout << (check_equals(num1, num2) ? "Yes" : "No");
    delete expr;
    return 0;
}
