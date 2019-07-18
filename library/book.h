#ifndef BOOK_H
#define BOOK_H

#include <QObject>
#include <QString>

class Book : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString author READ getAuthor WRITE setAuthor)
    Q_PROPERTY(QString title READ getTitle WRITE setTitle)
    Q_PROPERTY(float cost READ getCost WRITE setCost)
public:
    explicit Book(QObject *parent = 0);
    Book(QString a, QString t, float c, QObject *parent=0);

    void setAuthor(QString a);
    void setTitle(QString t);
    void setCost(float c);

    QString getAuthor() const;
    QString getTitle() const;
    float getCost() const;

signals:

public slots:

private:
    QString author;
    QString title;
    float cost;
};

#endif // BOOK_H
