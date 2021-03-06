#ifndef ITABLE_H
#define ITABLE_H

#include <QSqlTableModel>
#include <QFileDialog>
#include <QDebug>
#include <QProcess>

class ITable
{
public:
    ITable()
        : model(new QSqlTableModel())
    {}

    bool save()
    {
        QString fileName = QFileDialog::getSaveFileName(0,
         "Export Database", model->tableName() + ".sql", "Database file (*.sql)");

        if (!QFile(fileName).isWritable())
            return false;

        // TODO: file error processing

        QProcess dumpProcess;
        QStringList args;
        args << "--user=root" << "--password=root"
             << "--host=localhost" << QSqlDatabase::database().databaseName()
             << model->tableName();

        dumpProcess.setStandardOutputFile(fileName);
        dumpProcess.start("mysqldump", args);
        dumpProcess.waitForFinished(-1);
        qDebug() << "Dumping of " << model->tableName() << " complete";

        return true;
    }

    bool load()
    {
        QString fileName = QFileDialog::getOpenFileName(0,
         "Import Database", model->tableName() + ".sql", "Database file (*.sql)");

        if (!QFile(fileName).isReadable())
            return false;
        qDebug() << "fileName: " << fileName;

        // TODO: file error processing

        QProcess restoreProcess;
        QStringList args;
        args << "--user=root" << "--password=root"
             << "--host=localhost" << QSqlDatabase::database().databaseName();

        restoreProcess.setStandardInputFile(fileName);
        restoreProcess.start("mysql", args);
        restoreProcess.waitForFinished(-1);
        qDebug() << "Restoring of " << model->tableName() << " complete";

        return true;
    }

    virtual ~ITable() {}

    QSqlTableModel *model;
};
#endif // ITABLE_H
