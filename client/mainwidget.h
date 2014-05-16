#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QTableView>
#include <QGridLayout>
#include <QComboBox>
#include <QDebug>
#include "tablewidget.h"

class MainWidget : public QWidget
{
    Q_OBJECT
private:
    QGridLayout *layout;
    QSqlDatabase db;

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();

public slots:
    void editTable(QString table);

};

#endif // MAINWIDGET_H
