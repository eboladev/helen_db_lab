#include "tablewidget.h"

TableWidget::TableWidget(ITable *table)
    : table(table)
{
    layout = new QGridLayout(this);
    setLayout(layout);
    insertButton = new QPushButton("insert", this);
    deleteButton = new QPushButton("delete", this);
    saveButton = new QPushButton("export", this);
    loadButton = new QPushButton("import", this);

    view = new QTableView(this);
    view->setModel(table->model);

    layout->addWidget(view);
    layout->addWidget(insertButton);
    layout->addWidget(deleteButton);
    layout->addWidget(saveButton);
    layout->addWidget(loadButton);

    connect(insertButton, SIGNAL(clicked()), this, SLOT(insertRecord()));
    connect(deleteButton, SIGNAL(clicked()), this, SLOT(deleteSelected()));
    connect(saveButton, SIGNAL(clicked()), this, SLOT(save()));
    connect(loadButton, SIGNAL(clicked()), this, SLOT(load()));
}

void TableWidget::save()
{
    table->save();
}

void TableWidget::load()
{
    table->load();
}

void TableWidget::deleteSelected()
{
    QModelIndexList mi = view->selectionModel()->selectedRows();
    foreach (const QModelIndex &i,  mi) {
        table->model->removeRow(i.row());
    }

    table->model->select();
}

void TableWidget::insertRecord()
{
    QSqlRecord rc = table->model->record();
    for (int i = 0; i < rc.count(); ++i) {
        QString value = QInputDialog::getText(0, "Input field", rc.fieldName(i));
        rc.setValue(i, value);
    }

    table->model->insertRecord(table->model->rowCount(), rc);
    table->model->select();
}
