#include "date.h"

Date::Date(int D, int M, int Y)
{
    date = QDate(Y, M, D);
}

Date::Date(QDate d)
{
    date = QDate(d);
}

Date::Date() :
    date()
{
}

Date Date::NextDay()
{
    Date response = Date(date.addDays(1));
    return response;
}

Date Date::PreviousDay()
{
    Date response = Date(date.addDays(-1));
    return response;
}

bool Date::isLeap()
{
    return QDate::isLeapYear(date.year());
}

short Date::WeekNumber()
{
    return date.weekNumber();
}

int Date::DaysTillYourBirthday(Date birthdayDate) {  
    int ans = 0;
    if (birthdayDate.date.month() == 2 && birthdayDate.date.day() == 29) {

        if (QDate(date.year(), 3, 1) <= date && !QDate::isLeapYear(date.year() + 1)) {
            birthdayDate = birthdayDate.date.addDays(1);
            birthdayDate.setDate(birthdayDate.date.day(), birthdayDate.date.month(), date.year() + 1);
            qDebug() << 2 << "\n";
        }
        if (QDate(date.year(), 2, 28) >= date && !QDate::isLeapYear(date.year())) {
            birthdayDate = birthdayDate.date.addDays(1);
            birthdayDate.setDate(birthdayDate.date.day(), birthdayDate.date.month(), date.year());
            qDebug() << 1 << "\n";
        }

//        if (birthdayDate.date < date && QDate::isLeapYear(date.year() + 1)) {
//            birthdayDate = birthdayDate.date.addDays(1);
//            qDebug() << 1 << "\n";
//        }

    }
    else
        birthdayDate.setDate(birthdayDate.date.day(), birthdayDate.date.month(), date.year());
    if (birthdayDate.date < date) birthdayDate.setDate(birthdayDate.date.day(), birthdayDate.date.month(), date.year() + 1);
    ans = date.daysTo(birthdayDate.date);
    return ans;
}

int Date::Duration (Date d) {
    return date.daysTo(d.date);
}

void Date::setDate(int D, int M, int Y)
{
    date = QDate(Y, M, D);
}

const QString Date::toStr()
{
    return date.toString("dd.MM.yyyy");
}

Date Date::makeOpposite(){
    date.setDate(-date.year(), date.month(), date.day());
    return date;
}

int Date::year() {
    return date.year();
}
