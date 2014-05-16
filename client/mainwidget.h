#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlTableModel>
#include <QMessageBox>
#include <QTableView>
#include <QGridLayout>
#include <QDebug>

class MainWidget : public QWidget
{
    Q_OBJECT
private:
    QGridLayout *layout;

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();
};

#endif // MAINWIDGET_H
