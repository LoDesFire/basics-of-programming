#ifndef DATE_H
#define DATE_H

#include <QDate>
#include <QDebug>

class Date
{
private:
    QDate date;

public:
    Date(int, int, int);
    Date();
    Date(QDate);
    Date NextDay();
    Date PreviousDay();
    bool isLeap();
    short WeekNumber();
    int DaysTillYourBirthday(Date);
    int Duration (Date);
    void setDate(int, int, int);
    const QString toStr();
    Date makeOpposite();
    int year();
};

#endif // DATE_H
