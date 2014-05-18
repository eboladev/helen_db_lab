#ifndef IENTITY_H
#define IENTITY_H

#include <QSqlRecord>
#include <QSqlField>

class IEntity: public QSqlRecord
{
public:
    virtual QSqlField getId() = 0;
    virtual ~IEntity() {}
};

#endif // IENTITY_H
