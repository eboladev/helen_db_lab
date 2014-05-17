#include "tablewidget.h"

TableWidget::TableWidget(QWidget *parent) :
    QWidget(parent)
{

    layout = new QGridLayout(this);
    setLayout(layout);
    QPushButton *button = new QPushButton();
    QTableView *view = new QTableView();
    layout->addWidget(view);
    layout->addWidget(button);
}

void TableWidget::setDatabase(QSqlDatabase database)
{
    db = database;
    qDebug() << database.tables();
}
