#include "editprofile.h"
#include "ui_editprofile.h"
#include "homepage.h"
#include "login.h"
#include "databaseconnection.h"

Editprofile::Editprofile(QString text,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Editprofile)
{
    this->setFixedSize(600,500);
    LogginUser2editDets = text;
    ui->setupUi(this);

    ui->Usernamelabel->setText(LogginUser2editDets);

}

Editprofile::~Editprofile()
{
    delete ui;
}


void Editprofile::on_pushButton_clicked()
{
     QString newpassword1 = ui->newpassword1->text();
     QString newpassword2 = ui->newpassword2->text();

    QSqlQuery query1(QSqlDatabase::database("QMYSQL"));
    query1.prepare("UPDATE members SET password = :password WHERE username = :username");
    query1.bindValue(":username",LogginUser2editDets);
    query1.bindValue(":password",newpassword2);

    if (newpassword1.isEmpty() || newpassword2.isEmpty()) {

         QMessageBox::information(this,"NOT VALID","YOU HAVE NOT ENTERED PASSWORD IN BOTH FIELDS");
    }else {
         if (newpassword1 == newpassword2) {
             query1.exec();
             QMessageBox::information(this,"VALID","YOUR PASSWORD HAS BEEN UPDATED");


         }else{
             QMessageBox::information(this,"NOT VALID","BOTH PASSWORDS ARE NOT THE SAME");
         }
    }

}
void Editprofile::on_UpdatebuttonUsername_clicked()
{
     QString newusername = ui->usernameLogin->text();

    QSqlQuery query(QSqlDatabase::database("QMYSQL"));
    query.prepare("UPDATE members SET username = :username2 WHERE username = :username1");
    query.bindValue(":username1",LogginUser2editDets);
    query.bindValue(":username2",newusername);

    query.exec();
    QMessageBox::information(this,"VALID","YOUR USERNAME HAS BEEN UPDATED");

    this->newusername = newusername;
}

void Editprofile::on_ReturnHome_clicked()
{

    if (this->newusername.isEmpty()){
        // this->hide();
        homepage *picbacktohomepage;
        this->close();
        picbacktohomepage = new homepage(LogginUser2editDets, this);
        picbacktohomepage->show();
    }else {
        // this->hide();
        homepage *picbacktohomepage;
        this->close();
        picbacktohomepage = new homepage(this->newusername, this);
        picbacktohomepage->show();

    }

}
