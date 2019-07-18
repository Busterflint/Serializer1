#include "issuedbooks.h"
#include <QStringList>
#include <QList>

IssuedBooks::IssuedBooks()
{
}

void IssuedBooks::issueBook(QString n, QString t)
{
    issued.insert(n, t);
}

void IssuedBooks::returnBook(QString n, QString t)
{
    issued.remove(n, t);
}

// returns list of all books issued in form "name: title" for display of all issued books
QString IssuedBooks::allIssuedBooks() const
{
    QString output;
    QMapIterator<QString, QString> i(issued);
    while (i.hasNext())
    {
        i.next();
        output.append(QString(i.key()) + ": " + QString(i.value()) + "\n");
    }
    return output;
}

// returns a list of clients that have books issued for populating combo box, removing duplicates
QStringList IssuedBooks::allClients() const
{
    QStringList names;
    QMapIterator<QString, QString> i(issued);
    while (i.hasNext())
    {
        i.next();
        if (!names.contains(i.key()))
            names.append(i.key());
    }
    names.sort();
    return names;
}

// returns list of all books issued to a specific client, for populating combo box
QStringList IssuedBooks::booksForClient(QString n) const
{
    QList<QString> bookList;
    bookList.append(issued.values(n));
    QStringList books(bookList);
    books.sort();
    return books;
}

int IssuedBooks::count() const
{
    return issued.size();
}
