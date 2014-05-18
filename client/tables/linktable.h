#ifndef LINKTABLE_H
#define LINKTABLE_H

#include "ilinktable.h"
#include "entities/link.h"

class LinkTable : public ILinkTable<Link>
{
public:
    LinkTable();
    void save();
    void load();
    void addLink(Link &link);
};

#endif // LINKTABLE_H
