#include "entities.h"
#include "link.h"

template <typename entity_type>
class IEntityTable
{
public:
    IEntityTable() {}
    virtual void addEntity(entity_type &value) = 0;
    virtual entity_type operator[](int id) = 0;
    virtual void deleteEntity(int id) = 0;
};

template <typename ILink>
class ILinkTable
{
public:
    virtual void AddLink(ILink &link) = 0;

};

class LinkTable : public ILinkTable<Link>
{
public:

};
