#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <string>
#include<iostream>


#include "homepage.h"

QT_BEGIN_NAMESPACE

namespace Ui {
class Login;
}
QT_END_NAMESPACE


class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();


private slots:
    void on_registerBtn_clicked();

    void on_loginBtn_clicked();

private:
    Ui::Login *ui;
    //below new
    homepage *mainwindowchat;

};






#endif // LOGIN_H