#include "clientlist.h"

ClientList::ClientList()
{
}

void ClientList::addClient(Client *c)
{
    clientlist.append(c);
}

// returns a list of all client names to populate combo boxes
QStringList ClientList::returnClientNames() const
{
    QStringList names;
    for (int i=0; i<clientlist.size(); i++)
        names.append(clientlist.at(i)->getName());
    names.sort();
    return names;
}

ClientList::~ClientList()
{
    qDeleteAll(clientlist);
    clientlist.clear();
}

QList<Client *> ClientList::getList() const
{
    return clientlist;
}
