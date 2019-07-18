#include "booklist.h"

BookList::BookList()
{
}

void BookList::addBook(Book *b)
{
    booklist.append(b);
}

// returns a list of all titles to populate combo boxes
QStringList BookList::returnBookTitles() const
{
    QStringList titles;
    for (int i=0; i<booklist.size(); i++)
        titles.append(booklist.at(i)->getTitle());
    titles.sort();
    return titles;
}

BookList::~BookList()
{
    qDeleteAll(booklist);
    booklist.clear();
}

QList<Book *> BookList::getList() const
{
    return booklist;
}
