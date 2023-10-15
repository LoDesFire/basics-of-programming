#include "abiturient.h"

Abiturient::Abiturient(QString _FIO, QString _S1, QString _S2, QString _S3, float m[3]) : FIO(_FIO), subj1(_S1), subj2(_S2), subj3(_S3)
{
    for (int i = 0; i < 3; i++)
        mark[i] = m[i];
}

Abiturient *Abiturient::parse(QString arrStr[7])
{
    bool isValid = true, ok;
    float mark[3]{};
    mark[0] = arrStr[4].toFloat(&ok);
    if (mark[0] > 10.0 + 1e6)
        ok = false;
    isValid &= ok;
    mark[1] = arrStr[5].toFloat(&ok);
    if (mark[1] > 10.0 + 1e6)
        ok = false;
    isValid &= ok;
    mark[2] = arrStr[6].toFloat(&ok);
    if (mark[2] > 10.0 + 1e6)
        ok = false;
    isValid &= ok;

    if (isValid)
        return new Abiturient(arrStr[0], arrStr[1], arrStr[2], arrStr[3], mark);
    else
        return nullptr;

}

void Abiturient::print() {
    qDebug() << FIO << " " << subj1 << ": " << mark[0] << "\n" << subj2 << ": " << mark[1] << "\n" << subj3 << ": " << mark[2] << "\n";
}

QString *Abiturient::toString() {
    QString *tmp = new QString();
    *tmp = FIO;
    *tmp += "\n";
    *tmp += subj1;
    *tmp += "\n";
    *tmp += subj2;
    *tmp += "\n";
    *tmp += subj3;
    *tmp += "\n";
    *tmp += QString::number(mark[0]);
    *tmp += "\n";
    *tmp += QString::number(mark[1]);
    *tmp += "\n";
    *tmp += QString::number(mark[2]);
    *tmp += "\n";
    return tmp;
}

QString *Abiturient::toPlainText() const {
    QString *tmp = new QString();
    *tmp = "Ф.И.О: ";
    *tmp += FIO;
    *tmp += "\n";
    *tmp += subj1;
    *tmp += ": ";
    *tmp += QString::number(mark[0]);
    *tmp += "\n";
    *tmp += subj2;
    *tmp += ": ";
    *tmp += QString::number(mark[1]);
    *tmp += "\n";
    *tmp += subj3;
    *tmp += ": ";
    *tmp += QString::number(mark[2]);
    *tmp += "\n";
    return tmp;
}

QString Abiturient::getFIO() const {
    return FIO;
}

QString Abiturient::getSubject(int n) const {
    switch(n) {
    case 0:
        return subj1;
    case 1:
        return subj2;
    case 2:
        return subj3;
    }
    return NULL;
}

float Abiturient::getMark(int n) const {
    return mark[n];
}

float Abiturient::getSummary() const {
    return mark[0] + mark[1] + mark[2];
}
