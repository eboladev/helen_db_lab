#include "linktable.h"

LinkTable::LinkTable(QWidget *parent = 0)
    : model(new QSqlTableModel())
{
}

void LinkTable::addLink(int from, int to)
{
    QSqlRecord qr = model->record();
    qr.setValue(0, from);
    qr.setValue(1, to);
    model->insertRecord(model->rowCount(), qr);
    model->select();
}
