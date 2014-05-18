#include "ui/mainwidget.h"
#include <QApplication>
#include "tables/linktable.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;
    w.show();

//    LinkTable *lt = new LinkTable();

    return a.exec();
}
