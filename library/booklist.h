#ifndef BOOKLIST_H
#define BOOKLIST_H

#include "book.h"
#include <QStringList>

class BookList
{
public:
    BookList();
    ~BookList();
    void addBook(Book *b);
    QStringList returnBookTitles() const;
    QList<Book *> getList() const;
private:
    QList<Book *> booklist;
};

#endif // BOOKLIST_H
