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

    QPushButton *exportButton = new QPushButton("export database", this);
    QPushButton *importButton = new QPushButton("import database", this);
    layout->addWidget(exportButton, 0, 1);
    layout->addWidget(importButton, 0, 2);

    connect(comboBox, SIGNAL(activated(QString)), this, SLOT(editTable(QString)));
    connect(exportButton, SIGNAL(clicked()), this, SLOT(exportDatabase()));
}

void MainWidget::editTable(QString table)
{
    qDebug() << table << " openned";
    TableWidget *tw = new TableWidget();
    tw->setDatabase(db);
    tw->show();
}

void MainWidget::exportDatabase()
{
    QString fileName = QFileDialog::getOpenFileName(this,
    tr("Export Database"), "", tr("Database file (*.sql)"));

}

MainWidget::~MainWidget()
{

}
