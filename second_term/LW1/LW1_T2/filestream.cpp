#include "filestream.h"

FileStream::FileStream(QString fName) : filename(fName), isError(false), file(nullptr), stream(nullptr)
{
    if (filename != "") {
        file = new QFile(filename);
        file->open(QIODevice::ReadWrite);
        if (file->isOpen()) {
            stream = new QTextStream(file);
        }
        else isError = true;
    }
    else isError = true;
}

bool FileStream::loadFromFile(QVector<Abiturient *> &list) {
    if (isError)
        return false;

    QString arrStr[9];
    bool isValid = true;
    list.clear();

    while (!stream->atEnd() && isValid) {
        QString tmp;
        do {
            tmp = stream->readLine();
        } while (!stream->atEnd() && tmp == "");

        int count = 0;
        count++;
        arrStr[0] = tmp;

        for (; count < 9 && !stream->atEnd(); count++) {
            arrStr[count] = stream->readLine();
        }
        if (count != 9) isValid = false;

        if (isValid) {
            list.push_back(Abiturient::parseData(arrStr));
            if (*(list.end() - 1) == nullptr) {
                list.clear();
                return false;
            }
        }
    }
    return true;
}

bool FileStream::saveToFile(QVector<Abiturient *> &list) {
    if (isError)
        return false;

    file->close();
    delete file;
    delete stream;

    file = new QFile(filename);
    file->open(QIODevice::ReadWrite | QIODevice::Truncate);
    stream = new QTextStream(file);

    for (Abiturient *i : list) {
        (*stream) << i->getFIO() << "\n" << i->getMajor() << "\n" <<  i->getAverageMark() << "\n" << i->getSubject(0) << "\n" << i->getMark(0) << "\n" << i->getSubject(1) << "\n" << i->getMark(1) << "\n" << i->getSubject(2) << "\n" << i->getMark(2) << "\n\n";
    }

    return true;
}

FileStream::~FileStream()
{
    if (file) {
        file->close();
        delete file;
    }
    if (stream)
        delete stream;
}
