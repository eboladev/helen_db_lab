#include "entities.h"

QSqlField Link::getSourceId()
{
    return this->field(0);
}

QSqlField Link::getTargetId()
{
    return this->field(1);
}
