#include "employee.h"

Employee::Employee(QString _FIO, long long _number, int _hours, float _tariff) : FIO(_FIO), number(_number), tariff(_tariff), hours(_hours)
{}

Employee::Employee()
{
    tariff = f++;
}

int Employee::f = 0;
Employee *Employee::parse(QString arrStr[4])
{
    bool isValid = true, ok;
    long long num = arrStr[1].toLongLong(&ok);
    isValid &= ok;
    int hour = arrStr[2].toInt(&ok);
    isValid &= ok;
    float tarif = arrStr[3].toFloat(&ok);
    isValid &= ok;

    if (isValid)
        return new Employee(arrStr[0], num, hour, tarif);
    else
        return nullptr;

}

void Employee::print() {
    qDebug() << FIO << " " << number << " " << tariff << " " << hours << "\n";
}

QString *Employee::toString() {
    QString *tmp = new QString();
    *tmp = FIO;
    *tmp += "\n";
    *tmp += QString::number(number);
    *tmp += "\n";
    *tmp += QString::number(hours);
    *tmp += "\n";
    *tmp += QString::number(tariff);
    *tmp += "\n";

    return tmp;
}

QString *Employee::toPlainText() const {
    QString *tmp = new QString();
    *tmp = "Ф.И.О: ";
    *tmp += FIO;
    *tmp += "\nТабельный номер: ";
    *tmp += QString::number(number);
    *tmp += "\nРабочие часы: ";
    *tmp += QString::number(hours);
    *tmp += "\nТариф: ";
    *tmp += QString::number(tariff);
    *tmp += "\nЗарплата: ";
    *tmp += QString::number(getSalary());
    *tmp += "\n";

    return tmp;
}

QString Employee::getFIO() const {
    return FIO;
}

long long Employee::getNumber() const {
    return number;
}

float Employee::getTariff() const {
    return tariff;
}

int Employee::getHours() const {
    return hours;
}

double Employee::getSalary() const {
    if (hours > 144) {
        return double(2.0 * tariff) * (hours - 72);
    }
    return (double) tariff * hours;
}


