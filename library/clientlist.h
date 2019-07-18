#ifndef CLIENTLIST_H
#define CLIENTLIST_H

#include "client.h"
#include <QStringList>

class ClientList
{
public:
    ClientList();
    ~ClientList();
    void addClient(Client *c);
    QStringList returnClientNames() const;
    QList<Client *> getList() const;
private:
    QList<Client *> clientlist;
};

#endif // CLIENTLIST_H
