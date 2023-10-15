#ifndef FILESTREAM_H
#define FILESTREAM_H

#include <QTextStream>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QFileDialog>
#include <QVector>
#include "list.h"
#include "abiturient.h".h"

class FileStream
{
    QString filename;
    QFile *file;
    QTextStream *stream;
    bool isError;
public:
    FileStream(QString);
    ~FileStream();
    bool loadFromFile(List *&);
    bool saveTheFile(List *&);
    static bool saveToFile(List *&);

};

#endif // FILESTREAM_H
