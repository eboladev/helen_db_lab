#ifndef ILINKTABLE_H
#define ILINKTABLE_H

#include "itable.h"

template <typename ILink>
class ILinkTable : public ITable
{
public:
    virtual void addLink(ILink &link) = 0;
    virtual ~ILinkTable() {}
};

#endif // ILINKTABLE_H
