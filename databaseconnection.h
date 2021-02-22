#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

#include <QSqlDatabase>
#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
class databaseconnection
{


public:

    databaseconnection();
    void createData();
    bool connData();
    void discData();
};


#endif // DATABASECONNECTION_H
