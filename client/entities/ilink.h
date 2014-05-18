#ifndef ILINK_H
#define ILINK_H

#include <QSqlRecord>
#include <QSqlField>

class ILink : public QSqlRecord
{
public:
    virtual QSqlField getSourceId() = 0;
    virtual QSqlField getTargetId() = 0;
    virtual ~ILink() {}
};

#endif // ILINK_H
