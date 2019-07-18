#include "readfromfile.h"
#include "book.h"
#include "client.h"

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

ReadFromFile::ReadFromFile()
{
}

QList<QObject *> ReadFromFile::getData(QString type)
{
    QList<QObject *> objects;

    // get the file to open
    QString fileName = QFileDialog::getOpenFileName(0, QString("Open file"), QString("."), QString("Text files (*.txt)"));
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(0, "File error", "Could not open file " + fileName, QMessageBox::Ok);
    }
    else
    {
        QTextStream in(&file);

        // read in details
        QStringList data;
        while (!in.atEnd())
        {
            QString temp = in.readLine();
            if (temp.size()!=0)
                data.append(temp);
        }
        file.close();

        //process data
        int count;
        int counter = 0;
        if (type == "books")
        {
            count = data.size()/3;
            for (int loop=0; loop<count; loop++)
            {
                Book *temp = new Book;
                temp->setTitle(data.at(counter++));
                temp->setAuthor(data.at(counter++));
                temp->setCost(data.at(counter++).toFloat());
                objects.append(temp);
            }
        }
        else if (type == "clients")
        {
            count = data.size()/2;
            for (int loop=0; loop<count; loop++)
            {
                Client *temp = new Client;
                temp->setName(data.at(counter++));
                temp->setDate(QDate::fromString(data.at(counter++),"yyyy-MM-dd"));
                objects.append(temp);
            }
        }
    }
    return objects;
}
