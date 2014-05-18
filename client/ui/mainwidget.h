#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QComboBox>
#include <QGridLayout>
#include <QTableView>
#include <QMessageBox>
#include <QFileDialog>

#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>

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
    void exportDatabase();
//    void importDatabase();
};

#endif // MAINWIDGET_H
