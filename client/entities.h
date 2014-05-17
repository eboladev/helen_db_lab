#ifndef ENTITIES_H
#define ENTITIES_H

#include <QSqlRecord>
#include <QSqlField>

class EntityBase : public QSqlRecord
{
public:
    virtual QSqlField getId() = 0;
};

class Employee : public EntityBase
{
public:
    Employee();
    QSqlField getId();
};

class Manager : public EntityBase
{
public:
    Manager();
};

class Task : public EntityBase
{
public:
    Task();
};

class ILink : public EntityBase
{
public:
    virtual QSqlField getSourceId() = 0;
    virtual QSqlField getTargetId() = 0;
};

class Link : public ILink
{
public:
    QSqlField getSourceId();
    QSqlField getTargetId();
};

#endif // ENTITIES_H
