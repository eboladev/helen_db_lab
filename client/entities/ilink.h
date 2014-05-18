#ifndef ILINK_H
#define ILINK_H

#include <QSqlRecord>
#include <QSqlField>

class ILink : public QSqlRecord
{
public:
    virtual QSqlField getSourceId() = 0;
    virtual QSqlField getTargetId() = 0;
};

#endif // ILINK_H
