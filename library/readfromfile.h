#ifndef READFROMFILE_H
#define READFROMFILE_H

#include <QObject>
#include <QList>

class ReadFromFile
{
public:
    ReadFromFile();
    QList<QObject *> getData(QString type);
};

#endif // READFROMFILE_H
