#include "filewriter.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QMetaObject>
#include <QMetaProperty>
#include <booklist.h>
#include <clientlist.h>

FileWriter::FileWriter()
{
    filename = "default.txt";
}

void FileWriter::setFilename(QString f)
{
    filename = f;
}


void FileWriter::writeList(BookList *b)
{
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly))
    {
        QTextStream output(&file);
        QList<Book *> list = b->getList();

        foreach(QObject *obj, list)
            output << writeObject(obj);

        file.close();
    }
    else
        fileError();
}

void FileWriter::writeList(ClientList *c)
{
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly))
    {
        QTextStream output(&file);
        QList<Client *> list = c->getList();

        foreach(QObject *obj, list)
            output << writeObject(obj);

        file.close();
    }
    else
        fileError();
}

QString FileWriter::writeObject(QObject *obj)
{
    QString output;
    const QMetaObject *meta = obj->metaObject();

    for (int i=1; i<meta->propertyCount(); i++)
    {
        const QMetaProperty prop = meta->property(i);
        output.append(prop.read(obj).toString() + "\n");
    }
    output.append("\n");
    return output;
}

void FileWriter::fileError()
{
    QMessageBox error;
    error.setText("File could not be opened");
    error.exec();
}
