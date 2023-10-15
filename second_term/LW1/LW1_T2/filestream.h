#ifndef FILESTREAM_H
#define FILESTREAM_H

#include <QTextStream>
#include <QFile>
#include <QString>
#include <abiturient.h>
#include <QDebug>
#include <QVector>

class FileStream
{
    QString filename;
    QFile *file;
    QTextStream *stream;
    bool isError;
public:
    FileStream(QString);
    ~FileStream();
    bool loadFromFile(QVector<Abiturient *> &list);
    bool saveToFile(QVector<Abiturient *> &list);

};

#endif // FILESTREAM_H
