#ifndef LINK_H
#define LINK_H

#include "ilink.h"

class Link : public ILink
{
public:
    QSqlField getSourceId();
    QSqlField getTargetId();
};

#endif // LINK_H
