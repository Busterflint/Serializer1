#ifndef ISSUEDBOOKS_H
#define ISSUEDBOOKS_H

#include <QMultiMap>
#include <QString>

class IssuedBooks
{
public:
    IssuedBooks();
    void issueBook(QString n, QString t);
    void returnBook(QString n, QString t);
    QString allIssuedBooks() const;
    QStringList allClients() const;
    QStringList booksForClient(QString n) const;
    int count() const;
private:
    QMultiMap<QString, QString> issued;
};

#endif // ISSUEDBOOKS_H
