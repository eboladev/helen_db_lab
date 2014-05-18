#include "tablewidget.h"

TableWidget::TableWidget(ITable *table)
    : table(table)
{
    layout = new QGridLayout(this);
    setLayout(layout);
    deleteButton = new QPushButton("delete", this);
    saveButton = new QPushButton("export", this);
    loadButton = new QPushButton("import", this);

    view = new QTableView(this);
    view->setModel(table->model);

    layout->addWidget(view);
    layout->addWidget(deleteButton);
    layout->addWidget(saveButton);
    layout->addWidget(loadButton);

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
