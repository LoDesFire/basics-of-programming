#include "filestream.h"

FileStream::FileStream(QString fName) :
    filename(fName)
  , file(nullptr)
  , stream(nullptr)
  , isError(false)
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

bool FileStream::loadFromFile(List *&list) {
    if (isError)
        return false;

    QString arrStr[7];
    bool isValid = true;

    while (!stream->atEnd() && isValid) {
        int count = 0;
        for (; count < 7 && !stream->atEnd(); count++) {
            arrStr[count] = stream->readLine();
        }
        if (count != 7) return false;

        Abiturient *tmp = Abiturient::parse(arrStr);
        if (tmp) list->push_back(tmp);
        else
            return false;
    }
    return true;
}

bool FileStream::saveTheFile(List *&list) {
    if (isError)
        return false;

    file->close();
    delete file;
    delete stream;
    file = new QFile(filename);
    file->open(QIODevice::ReadWrite | QIODevice::Truncate);
    stream = new QTextStream(file);

    if (list)
        for (unsigned long long i = 0; i < list->get_size(); i++) {
            (*stream) << *((list->operator [](i))->toString());
        }

    return true;
}

bool FileStream::saveToFile(List *&list) {
    FileStream *fs = new FileStream(QFileDialog::getSaveFileName(nullptr, "Open File", "/Users/lllymuk/Desktop/OAiP/OAiP 2 sem/LW2_T1_2/"));
    if (fs->isError || !fs->saveTheFile(list)) {
        delete fs;
        return false;
    }

    delete fs;
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
