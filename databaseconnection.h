#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

#include <QSqlDatabase>
#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
/**
 * @brief
 *
 */
class databaseconnection
{


public:

    /**
     * @brief
     *
     */
    databaseconnection();
    /**
     * @brief
     *
     */
    void createData();
    /**
     * @brief
     *
     * @return bool
     */
    bool connData();
    /**
     * @brief
     *
     */
    void discData();
};


#endif // DATABASECONNECTION_H
