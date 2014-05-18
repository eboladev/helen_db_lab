#ifndef LINKTABLE_H
#define LINKTABLE_H

#include <QSqlDatabase>
#include <QDebug>
#include "tables/ilinktable.h"
#include "entities/link.h"

class LinkTable : public ILinkTable<Link>
{
public:
    LinkTable();
    void addLink(Link &link) {};
    void addLink(int from, int to);

    virtual ~LinkTable() {};
};

#endif // LINKTABLE_H
