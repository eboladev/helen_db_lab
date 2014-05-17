#include "entities.h"

QSqlField Employee::getId()
{
    return this->field(0);
}
