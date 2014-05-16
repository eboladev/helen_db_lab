#include "tablewidget.h"

TableWidget::TableWidget(QWidget *parent) :
    QWidget(parent)
{

    layout = new QGridLayout(this);
    setLayout(layout);
    QPushButton button;
    layout->addWidget(&button);
}

void TableWidget::setDatabase(QSqlDatabase database)
{
    qDebug() << database.tables();

}
