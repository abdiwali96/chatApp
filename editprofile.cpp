#include "editprofile.h"
#include "ui_editprofile.h"
#include "homepage.h"
#include "login.h"
#include "databaseconnection.h"

Editprofile::Editprofile(User* User1,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Editprofile)
{
    this->setFixedSize(600,500);

   // LogginUser2editDets = User1->getUsername();

    this->User1 = User1 ;


    ui->setupUi(this);
    ui->Usernamelabel->setText(User1->getUsername());

}

Editprofile::~Editprofile()
{
    delete ui;
}

User* Editprofile::GetObject(){
    return User1 ;
}

void Editprofile::SetObject(QString s) {
      User1->setUsername(s);
}


void Editprofile::on_pushButton_clicked()
{
   //  QString newpassword1 = ui->newpassword1->text();
   //  QString newpassword2 = ui->newpassword2->text();

    QSqlQuery query1(QSqlDatabase::database("QMYSQL"));
    query1.prepare("UPDATE members SET password = :password WHERE username = :username");
    query1.bindValue(":username",this->GetObject()->getUsername());
    query1.bindValue(":password",ui->newpassword2->text());

    if (ui->newpassword1->text().isEmpty() || ui->newpassword2->text().isEmpty()) {

         QMessageBox::information(this,"NOT VALID","YOU HAVE NOT ENTERED PASSWORD IN BOTH FIELDS");
    }else {
         if (ui->newpassword1->text() == ui->newpassword2->text()) {
             query1.exec();
             QMessageBox::information(this,"VALID","YOUR PASSWORD HAS BEEN UPDATED");         

         }else{
             QMessageBox::information(this,"NOT VALID","BOTH PASSWORDS ARE NOT THE SAME");
         }
    }

}
void Editprofile::on_UpdatebuttonUsername_clicked()
{
    if (ui->usernameLogin->text().isEmpty()){
         QMessageBox::information(this,"NOT VALID","USERNAME NOT ENTERED");
    }else {
        QSqlQuery query(QSqlDatabase::database("QMYSQL"));

          query.prepare("UPDATE members SET username = :username2 WHERE username = :username1");
          query.bindValue(":username1",this->GetObject()->getUsername());
          query.bindValue(":username2",ui->usernameLogin->text());

          query.exec();
          QMessageBox::information(this,"VALID","YOUR USERNAME HAS BEEN UPDATED");
          this->SetObject(ui->usernameLogin->text());

    }



}

void Editprofile::on_ReturnHome_clicked()
{

    homepage *picbacktohomepage;
    this->close();
    picbacktohomepage = new homepage(this->GetObject(), this);
    picbacktohomepage->show();

}


