#ifndef FILESTREAM_H
#define FILESTREAM_H

#include <QTextStream>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QFileDialog>
#include <QVector>
#include "stack.h"

class FileStream
{
    QString filename;
    QFile *file;
    QTextStream *stream;
    bool isError;
public:
    FileStream(QString);
    ~FileStream();
    bool readLineFromFile(QString &);
    bool saveToFile(QString);
    bool removeFile();
    void toBegin();

};

#endif // FILESTREAM_H
