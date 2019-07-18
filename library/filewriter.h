#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <QString>
#include <QObject>

class BookList;
class ClientList;

class FileWriter
{
public:
    FileWriter();
    void setFilename(QString f);
    void writeList(BookList *b);
    void writeList(ClientList *c);
private:
    QString writeObject(QObject *obj);
    void fileError();

    QString filename;
};

#endif // FILEWRITER_H
