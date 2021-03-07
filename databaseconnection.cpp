#include "databaseconnection.h"
#include <QSqlDatabase>

#include<QDebug>

databaseconnection::databaseconnection()
{

}

void databaseconnection::createData(){
    QSqlDatabase database1 = QSqlDatabase::addDatabase("QMYSQL");
    database1.setHostName("localhost");
    database1.setUserName("admin");
    database1.setPassword("admin");
    database1.setDatabaseName("chatappdb");


}
bool databaseconnection::connData()
{
    QSqlDatabase database1 = QSqlDatabase::addDatabase("QMYSQL");
     database1.setHostName("localhost");
     database1.setUserName("admin");
     database1.setPassword("admin");
     database1.setDatabaseName("chatappdb");

        if(!database1.open())
            {
               qDebug()<<("Failed to open Database");

               return false;
            }
            else
            {
                qDebug()<<("Connected.....");

                return true;
            }

}

void databaseconnection::discData() {


    QSqlDatabase::removeDatabase("database1");


}
