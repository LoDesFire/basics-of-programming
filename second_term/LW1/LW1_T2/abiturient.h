#ifndef ABITURIENT_H
#define ABITURIENT_H

#include <QString>
#include "QDebug"

class Abiturient
{

    QString FIO, subject[3], speciality;
    float averageMark;
    int mark[3];

public:
    Abiturient();
    Abiturient(QString, QString, float, QString [3], int [3]);
    static Abiturient *parseData(QString [9]);
    void printData();
    QString getFIO() const;
    int getMark(int) const;
    QString getSubject(int) const;
    QString getMajor() const;
    float getAverageMark() const;
    int getSummaryMark() const;
};

#endif // ABITURIENT_H
