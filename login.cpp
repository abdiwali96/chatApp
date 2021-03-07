#include "login.h"
#include "ui_login.h"

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


        QImage image;
        QByteArray byte;

        QFile file(":/images/emptyprofilepic.png");
        byte = file.readAll();
        if(file.open(QIODevice::ReadOnly))
            {
                byte = file.readAll();
                file.close();
            }



        QSqlQuery qry(QSqlDatabase::database("QMYSQL"));

        qry.prepare("INSERT INTO members (username,password,email,mobile,ProfilePic,Numberoffriends)"
                    "VALUES (:username,:password,:email,:mobile,:ProfilePic,:Numberoffriends)");

        qry.bindValue(":username", username);
        qry.bindValue(":password", password);
        qry.bindValue(":email", email);
        qry.bindValue(":mobile", mobile);

        qry.bindValue(":ProfilePic", byte , QSql::In | QSql::Binary);


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
        //condition below is if condition fails to execute
        query.exec();

         if(query.next()){
             QString User1_ID = query.value(0).toString();
             QString User1_Username = query.value(1).toString();
             QString User1_Email = query.value(3).toString();
             QString User1_Mobile = query.value(4).toString();
                         //AVATAR
            QByteArray PictureFromDatabase =query.value(5).toByteArray();
            QPixmap User1_Profile = QPixmap();
            User1_Profile.loadFromData(PictureFromDatabase);
                         //FriendsID
             QString User1_friendslistnum = query.value(6).toString();
             User1 = new User(User1_ID,User1_Username,User1_Email, User1_Mobile, User1_Profile, User1_friendslistnum);
             QMessageBox::information(this,"Success","You are logged in");

             this->hide();
             QString SendOverUsername = ui->usernameLogin->text();
             mainwindowchat = new homepage(User1, this);
             mainwindowchat->show();

           } else{

                 QMessageBox::information(this,"Error","Wrong password or username");
           }

    }else {
        QMessageBox::information(this,"DATABASE FAILED", "Database connection failed");
    }
}
