#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QSqlDatabase>
#include <QDebug>

class TableWidget : public QWidget
{
    Q_OBJECT
private:
    QGridLayout *layout;
    QSqlDatabase db;
public:
    explicit TableWidget(QWidget *parent = 0);
    void setDatabase(QSqlDatabase database);

signals:

public slots:

};

#endif // TABLEWIDGET_H
