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
