#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

#include <QSqlDatabase>
class databaseconnection
{


public:

    databaseconnection();
    void createData();
    bool connData();
    void discData();
};


#endif // DATABASECONNECTION_H
