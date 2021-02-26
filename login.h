#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <string>
#include<iostream>

#include "user.h"
#include "homepage.h"
#include "databaseconnection.h"

QT_BEGIN_NAMESPACE

namespace Ui {
class Login;
}
QT_END_NAMESPACE


/**
 * @brief
 *
 */
class Login : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief
     *
     * @param parent
     */
    explicit Login(QWidget *parent = nullptr);
    /**
     * @brief
     *
     */
    ~Login();


private slots:
    /**
     * @brief
     *
     */
    void on_registerBtn_clicked();

    /**
     * @brief
     *
     */
    void on_loginBtn_clicked();

private:
    Ui::Login *ui; /**< TODO: describe */

    User *User1; /**< TODO: describe */

    //below new
    homepage *mainwindowchat; /**< TODO: describe */

};






#endif // LOGIN_H
