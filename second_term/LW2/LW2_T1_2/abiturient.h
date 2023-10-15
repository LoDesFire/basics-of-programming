#ifndef ABITURIENT_H
#define ABITURIENT_H

#include <QString>
#include <QDebug>

class Abiturient
{
    QString FIO, subj1, subj2, subj3;
    float mark[3];
public:
    Abiturient(QString, QString, QString, QString, float[3]);
    Abiturient();
    static Abiturient *parse(QString [7]);
    void print();
    QString *toString();
    QString getFIO() const;
    QString *toPlainText() const;
    QString getSubject(int) const;
    float getMark(int) const;
    float getSummary() const;
};

#endif // ABITURIENT_H
