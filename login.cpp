#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include <string>
#include<iostream>

#include "databaseconnection.h"
#include "homepage.h"

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    this->setFixedSize(1010,750);
    ui->username->setPlaceholderText("Enter Username");
    ui->password->setPlaceholderText("Enter Password");
    ui->email->setPlaceholderText("Enter Email");
    ui->mobile->setPlaceholderText("Enter Mobile");
    ui->usernameLogin->setPlaceholderText("Please Enter Username");
    ui->passwordLogin->setPlaceholderText("Please Enter Password");



}




Login::~Login()
{
    delete ui;
}

void Login::on_registerBtn_clicked()
{
    databaseconnection Login;
    Login.connData();
    if (Login.connData() == true)
       {
        // Get data from the input fields
        QString username = ui->username->text();
        QString password = ui->password->text();
        QString email = ui->email->text();
        QString mobile = ui->mobile->text();



        //now this Query will insert the captured data above in to database

        QSqlQuery qry(QSqlDatabase::database("QMYSQL"));

        qry.prepare("INSERT INTO members (username,password,email,mobile,ProfilePic,Numberoffriends)"
                    "VALUES (:username,:password,:email,:mobile,:ProfilePic,:Numberoffriends)");

        qry.bindValue(":username", username);
        qry.bindValue(":password", password);
        qry.bindValue(":email", email);
        qry.bindValue(":mobile", mobile);
        qry.bindValue(":ProfilePic", "");
        qry.bindValue(":Numberoffriends", "");

        if(qry.exec()){

            QMessageBox::information(this, "Inserted", "Data is Inserted Succesfully");
        }else {
            QMessageBox::information(this, "NOT Inserted", "Data is NOT Inserted Succesfully");
        }




       }else {

        QMessageBox::information(this,"Not Connected","Database is not connected");

    }


}
void Login::on_loginBtn_clicked()
{

    databaseconnection registercon;
    registercon.connData();
    if (registercon.connData() == true)
    {

        QMessageBox::information(this,"DATABASE CONNECTED", "Database connection ");

        //Get user data input
        QString username = ui->usernameLogin->text();
        QString password = ui->passwordLogin->text();

        //queries db to find user&pass
        QSqlQuery query(QSqlDatabase::database("QMYSQL"));
        query.prepare(QString("SELECT * FROM members WHERE username = :username AND password = :password"));

        query.bindValue(":username",username);
        query.bindValue(":password",password);

        //results of the query

        //condition below is if condition fails to execute
        query.exec();

         if(query.next()){

                 QMessageBox::information(this,"Success","You are logged in");

                  this->hide();

                  QString SendOverUsername = ui->usernameLogin->text();

                  mainwindowchat = new homepage(SendOverUsername, this);
                  mainwindowchat->show();



           } else{

                 QMessageBox::information(this,"Error","Wrong password or username");

           }



    }else {
        QMessageBox::information(this,"DATABASE FAILED", "Database connection failed");
    }

}
