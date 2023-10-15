#include "opz.h"

OPZ::OPZ()
{

}

bool OPZ::isOperator(QCharRef c) {
    return c == '-' || c == '+' || c == '*' || c == '^' || c == '/' || c == '~';
}
bool OPZ::isOperator(char c) {
    return c == '-' || c == '+' || c == '*' || c == '^' || c == '/' || c == '~';
}

QString *OPZ::exprToOPZ(QString str) {
    QString input = str;
    QString *output = new QString;

    Stack<char> oper;
    Stack<double> s;
    s.clear();
    oper.clear();

    for (int i = 0; i < input.length(); i++) {
        if (input[i] == ' ')
            input.remove(i--, 1);
    }

    if (input[0] == '-')
        input[0] = '~';

    for (int i = 1; i < input.length(); i++) {
        if ((input[i - 1] > '9' || input[i - 1] < '0') && input[i] == '-' && input[i-1] != ')')
            input[i] = '~';

        if (isOperator(input[i - 1]) && isOperator(input[i]) ) {
            (*output) = "Error";
            return output;
        }
    }

    for (int i = 0; i < input.length(); i++) {
        QString number;
        while (i < input.length() && ((input[i] <= '9' && input[i] >= '0') || ( input[i] == '.' ))) {
            number += input[i];
            i++;
        }
        if (number.length() > 0) {
            i--;
            bool ok;
            number.toDouble(&ok);
            if (!ok) {
                (*output) = "Error";
                return output;
            }
            else
            {
                if (output->length())
                    (*output) += ' ';
                (*output) += number;
            }
        }
        else {
            if (input[i] == '-' || input[i] == '+' || input[i] == '*' || input[i] == '/' || input[i] == '^' || input[i] == '~' || input[i] == '(' || input[i] == ')') {
                switch(input.toStdString()[i]) {
                case '~':
                    while (!oper.empty() && oper.top() == '^') {
                        if (output->length())
                            (*output) += ' ';
                        (*output) += oper.top();
                        oper.pop();
                    }
                    oper.push('~');
                    break;
                case '+':
                case '-':
                    while (!oper.empty() && (oper.top() == '^' || oper.top() == '/' || oper.top() == '*' || oper.top() == '+' || oper.top() == '-' || oper.top() == '~')) {
                        if (output->length())
                            (*output) += ' ';
                        (*output) += oper.top();
                        oper.pop();
                    }
                    oper.push(input.toStdString()[i]);
                    break;
                case '*':
                case '/':
                    while (!oper.empty() && (oper.top() == '^' || oper.top() == '/' || oper.top() == '*' || oper.top() == '~')) {
                        if (output->length())
                            (*output) += ' ';
                        (*output) += oper.top();
                        oper.pop();
                    }
                    oper.push(input.toStdString()[i]);
                    break;
                case '^':
                    oper.push('^');
                    break;
                case '(':
                    oper.push('(');
                    break;
                case ')':
                    if (oper.empty()) {
                        (*output) = "Error";
                        return output;
                    }


                    while (!oper.empty() && oper.top() != '(') {
                        if (output->length())
                            (*output) += ' ';
                        (*output) += oper.top();
                        oper.pop();
                    }
                    if (!oper.empty())
                        oper.pop();
                    break;
                }
            }
            else {
                (*output) = "Error";
                return output;
            }
        }
    }
    while (!oper.empty()) {
        if (output->length())
            (*output) += ' ';
        (*output) += oper.top();
        oper.pop();
    }
    return output;
}

double OPZ::calculate(QString str, bool &isError) {
    Stack<double> s;
    QString input = str;
    for (int i = 0; i < input.length(); i++) {
        QString number;
        if (input[i] == ' ')
            continue;
        while (i < input.length() && ((input[i] <= '9' && input[i] >= '0') || ( input[i] == '.' ))) {
            number += input[i];
            i++;
        }

        if (number.length() > 0) {
            i--;
            bool ok;
            double tmp = number.toDouble(&ok);
            if (!ok) {
                isError = false;
                return 0;
            }
            else
                s.push(tmp);
        }
        else {
            double p1, p2;
            if (!s.empty()) {
                p1 = s.top();
                s.pop();
            }
            else {
                isError = false;
                return 0;
            }
            if (input[i] != '~') {
                if (!s.empty()) {
                    p2 = s.top();
                    s.pop();
                }
                else {
                    isError = false;
                    return 0;
                }
                switch(input.toStdString()[i]) {
                case '+':
                    s.push(p1 + p2);
                    break;
                case '-':
                    s.push(p2 - p1);
                    break;
                case '/':
                    s.push(p2 / p1);
                    break;
                case '*':
                    s.push(p2 * p1);
                    break;
                case '^':
                    s.push(powl(p2, p1));
                    break;
                default:
                    isError = false;
                    return 0;
                }
            }
            else {
                s.push(-p1);
            }
        }
    }
    if (!s.empty()) {
        isError = true;
        return s.top();
    }
    else {
        isError = false;
        return 0;
    }
}
