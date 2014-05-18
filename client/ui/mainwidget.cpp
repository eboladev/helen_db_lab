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

    layout = new QGridLayout(this);
    setLayout(layout);
//    table->addLink(13, 12);

    QComboBox *comboBox = new QComboBox(this);
    comboBox->addItems(db.tables());
    layout->addWidget(comboBox);

    connect(comboBox, SIGNAL(activated(QString)), this, SLOT(editTable(QString)));
}

void MainWidget::editTable(QString tableName)
{
    LinkTable *table = new LinkTable();
    table->model->setTable(tableName);
    table->model->setEditStrategy(QSqlTableModel::OnFieldChange);
    table->model->select();

    qDebug() << table << " openned";
    TableWidget *tw = new TableWidget(table);
    tw->show();
}

MainWidget::~MainWidget()
{

}
