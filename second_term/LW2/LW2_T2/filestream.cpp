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

bool FileStream::readLineFromFile(QString &str) {
    if (isError || stream->atEnd())
        return false;
    str = stream->readLine();
    return true;
}

bool FileStream::saveToFile(QString s) {
    if (isError)
        return false;

    (*stream) << s;
    return true;
}

bool FileStream::removeFile() {
    return file->remove();
}

void FileStream::toBegin() {
    stream->seek(0);
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
