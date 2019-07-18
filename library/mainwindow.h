#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "booklist.h"
#include "clientlist.h"
#include "issuedbooks.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void addBook();
    void addClient();
    void issueBook();
    void returnBook();
    void listIssued();
    void updateReturnBook();
    void writeToFile();
    void readFromFile();

private:
    Ui::MainWindow *ui;

    // lists for books, clients, and issued books
    BookList *booklist;
    ClientList *clientlist;
    IssuedBooks issuedBooks;
};

#endif // MAINWINDOW_H
