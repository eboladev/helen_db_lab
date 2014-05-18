#ifndef ITABLE_H
#define ITABLE_H

class ITable
{
public:
    virtual void save() = 0;
    virtual void load() = 0;
    virtual ~ITable() {}
};
#endif // ITABLE_H
