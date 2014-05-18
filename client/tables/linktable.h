#ifndef LINKTABLE_H
#define LINKTABLE_H

#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QDebug>
#include "ilinktable.h"
#include "entities/link.h"

class LinkTable : public ILinkTable<Link>
{
    Q_OBJECT
public:
    LinkTable(QWidget *parent);
    void save();
    void load();
    void addLink(Link &link);
    void addLink(int from, int to);

    QSqlTableModel *model;
};

#endif // LINKTABLE_H
