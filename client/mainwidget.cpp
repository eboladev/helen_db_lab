#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *button = new QPushButton(this);
    button->setText("Add item");
    button->show();
    this->setGeometry(700, 200, 200, 200);
}

MainWidget::~MainWidget()
{

}
