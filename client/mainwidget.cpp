#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("organisation");
    db.setUserName("root");
    db.setPassword("root");
    if(!db.open()) {
        QMessageBox::information(this, "Error", "Couldn't open database!");
        emit exit(0);
    }
    qDebug() << "Connected succesfully";
    QSqlTableModel *model = new QSqlTableModel(this, db);
    model->setTable("employees");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
//    QPushButton *button = new QPushButton(this);
//    button->setText("Add item");
//    button->show();

    layout = new QGridLayout(this);
    setLayout(layout);

    QTableView *view = new QTableView(this);
    view->setModel(model);
    layout->addWidget(view);
    layout->addWidget(new QPushButton());
}

MainWidget::~MainWidget()
{

}
