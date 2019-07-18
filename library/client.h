#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QString>
#include <QDate>

class Client : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName)
    Q_PROPERTY(QDate date READ getDate WRITE setDate)

public:
    explicit Client(QObject *parent = 0);
    Client(QString n, QDate d, QObject *parent=0);

    void setName(QString n);
    QString getName() const;
    void setDate(QDate d);
    QDate getDate() const;

signals:

public slots:

private:
    QString name;
    QDate date;
};

#endif // CLIENT_H
