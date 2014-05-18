#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlField>
#include <QInputDialog>
#include <QTableView>
#include <QDebug>
#include "tables/itable.h"

class TableWidget : public QWidget
{
    Q_OBJECT
private:
    QGridLayout *layout;
    QTableView *view;
    QPushButton *deleteButton;
    QPushButton *saveButton;
    QPushButton *loadButton;
    QPushButton *insertButton;
    ITable *table;

public:
    explicit TableWidget(ITable *table);

signals:

public slots:
    void save();
    void load();
    void deleteSelected();
    void insertRecord();
};

#endif // TABLEWIDGET_H
