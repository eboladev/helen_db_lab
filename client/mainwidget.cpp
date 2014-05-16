#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("organisation");
    db.setUserName("root");
    db.setPassword("root");

    if(!db.open()) {
        QMessageBox::information(this, "Error", "Couldn't connect to database!");
        emit exit(0);
    } else {
        qDebug() << "Connected succesfully";
    }

//    QSqlTableModel *model = new QSqlTableModel(this, db);
//    model->setTable("employees");
//    model->setEditStrategy(QSqlTableModel::OnFieldChange);
//    model->select();

    layout = new QGridLayout(this);
    setLayout(layout);

//    QTableView *view = new QTableView(this);
//    view->setModel(model);
//    layout->addWidget(view);

    QComboBox *comboBox = new QComboBox(this);
    comboBox->addItems(db.tables());
    layout->addWidget(comboBox);
    QPushButton *button = new QPushButton("open table", this);
    layout->addWidget(button, 0, 1);
    connect(comboBox, SIGNAL(activated(QString)), this, SLOT(editTable(QString)));
}

void MainWidget::editTable(QString table)
{
    qDebug() << table << " openned";
    TableWidget *tw = new TableWidget();
    tw->setDatabase(db);
    tw->show();
}

MainWidget::~MainWidget()
{

}
