#ifndef IENTITYTABLE_H
#define IENTITYTABLE_H

#include "itable.h"

template <typename entity_type>
class IEntityTable : public ITable
{
public:
    virtual void addEntity(entity_type &value) = 0;
    virtual entity_type operator[](int id) = 0;
    virtual void deleteEntity(int id) = 0;
    virtual ~IEntityTable() {}
};

#endif // IENTITYTABLE_H
