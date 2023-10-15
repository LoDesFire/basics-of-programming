#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QString>
#include <QDebug>

class Employee
{
    QString FIO;
    long long number;
    float tariff;
    int hours;
public:
    Employee(QString, long long, int, float);
    Employee();
    static int f;
    static Employee *parse(QString [4]);
    void print();
    QString *toString();
    QString getFIO() const;
    QString *toPlainText() const;
    long long getNumber() const;
    float getTariff() const;
    int getHours() const;
    double getSalary() const;
};

#endif // EMPLOYEE_H
