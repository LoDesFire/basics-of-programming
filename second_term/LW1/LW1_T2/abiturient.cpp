#include "abiturient.h"

Abiturient::Abiturient()
{
}

Abiturient::Abiturient(QString _FIO, QString _Major, float _avMark, QString _subject[3], int _mark[3])
{
    FIO = _FIO;
    speciality = _Major;
    averageMark = _avMark;
    for (int i = 0; i < 3; i++)
        mark[i] = _mark[i];
    for (int i = 0; i < 3; i++)
        subject[i] = _subject[i];
}

Abiturient *Abiturient::parseData(QString arrStr[9])
{
    Abiturient *abit = new Abiturient();
    bool res = true, ok;
    abit->FIO = arrStr[0];
    abit->speciality = arrStr[1];
    abit->averageMark = arrStr[2].toDouble(&ok);
    res &= ok;
    abit->subject[0] = arrStr[3];
    abit->subject[1] = arrStr[5];
    abit->subject[2] = arrStr[7];
    abit->mark[0] = arrStr[4].toInt(&ok);
    res &= ok;
    abit->mark[1] = arrStr[6].toInt(&ok);
    res &= ok;
    abit->mark[2] = arrStr[8].toInt(&ok);
    res &= ok;
    //qDebug() << (res ? abit : nullptr) << "\n";
    return res ? abit : nullptr;
}

QString Abiturient::getFIO() const {
    return FIO;
}

int Abiturient::getMark(int n) const {
    return mark[n];
}

QString Abiturient::getSubject(int n) const {
    return subject[n];
}

QString Abiturient::getMajor() const {
    return speciality;
}

float Abiturient::getAverageMark() const {
    return averageMark;
}

int Abiturient::getSummaryMark() const {
    return int(averageMark * 10) + mark[0] + mark[1] + mark[2];
}

void Abiturient::printData()
{
    qDebug() << "Full name: " << FIO << "\nMajor: " << speciality << "\nSummary: " << this->getSummaryMark() << "\n";
}
