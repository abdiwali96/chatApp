#include "contentsearch.h"
#include "ui_contentsearch.h"
#include "homepage.h"

contentsearch::contentsearch(User* User1,User* User2, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::contentsearch)
{
    ui->setupUi(this);
    this->setFixedSize(1107,783);

   this->User1 = User1;
   this->User2 = User2;
}

contentsearch::~contentsearch()
{
    delete ui;
}


User* contentsearch::GetObject(){
    return User1 ;
}

void contentsearch::SetObject(QString s) {
      User1->setUsername(s);
}

User* contentsearch::GetObject2(){
    return User2;
}

void contentsearch::SetObject2(QString s) {
      User2->setUsername(s);
}

void contentsearch::on_Searchbutton_clicked()
{
   ui->listofmessages->clear();
   QString searchphrase = ui->SearchBox->text();

   QSqlQuery queryH(QSqlDatabase::database("QMYSQL"));
   queryH.prepare(QString("SELECT * FROM ChatLogs WHERE User1log = :User1log"));
   queryH.bindValue(":User1log",this->GetObject()->getUsername());

   queryH.exec();

  while(queryH.next()){
      QString dbmessage = queryH.value(5).toString();
      QStringList fl = dbmessage.split(",");

      for ( const auto& i : fl)
      {
         // qDebug() << i;
          QString elementMessage = i;
          if (i.contains(ui->SearchBox->text())){

            this->Themessage = dbmessage;
          ui->listofmessages->addItem(elementMessage);

          }

      }

  }


}

void contentsearch::on_editselect_clicked()
{
    QString dbmessageline = ui->listofmessages->currentItem()->text();
    QStringList fl = dbmessageline.split(":");
    ui->lineEdit->setText(fl.last());


}

void contentsearch::on_listofmessages_itemClicked()
{
   // this->editdbmessage = ui->listofmessages->currentItem()->text();
   //  qDebug() << this->editdbmessage;
}

void contentsearch::on_pushButton_4_clicked()
{
    QString dbmessageline2 = ui->listofmessages->currentItem()->text();
    QStringList fl2 = dbmessageline2.split(":");
    QString oldphrase =  fl2.last();


    this->editdbmessage = ui->lineEdit->text();


   qDebug() << this->Themessage;
   QString editmessage =  Themessage;

   this->Themessage.replace(oldphrase,this->editdbmessage);
   qDebug() << this->Themessage;


   QSqlQuery queryH(QSqlDatabase::database("QMYSQL"));
   queryH.prepare("UPDATE ChatLogs SET Message = :NewMessage WHERE User1log = :User1log AND Message = :Message OR User2log = :User2log AND Message = :Message");
   queryH.bindValue(":User1log",this->GetObject()->getUsername());
   queryH.bindValue(":User2log",this->GetObject()->getUsername());
   queryH.bindValue(":Message",editmessage);
   queryH.bindValue(":NewMessage",this->Themessage);

   queryH.exec();
    QMessageBox::information(this,"Success","Message has been updated");
    ui->lineEdit->clear();
    ui->listofmessages->clear();

}

void contentsearch::on_deletemessagebtn_clicked()
{
    QString dbmessageline2 = ui->listofmessages->currentItem()->text();
    QStringList fl2 = dbmessageline2.split(":");
    QString oldphrase =  fl2.last();


    this->editdbmessage = ui->lineEdit->text();


   qDebug() << this->Themessage;
   QString editmessage =  Themessage;

   this->Themessage.replace(oldphrase,"");
   qDebug() << this->Themessage;


   QSqlQuery queryH(QSqlDatabase::database("QMYSQL"));
   queryH.prepare("UPDATE ChatLogs SET Message = :NewMessage WHERE User1log = :User1log AND Message = :Message OR User2log = :User2log AND Message = :Message");
   queryH.bindValue(":User1log",this->GetObject()->getUsername());
   queryH.bindValue(":User2log",this->GetObject()->getUsername());
   queryH.bindValue(":Message",editmessage);
   queryH.bindValue(":NewMessage",this->Themessage);

   queryH.exec();
    QMessageBox::information(this,"Success","Message has deleted");
    ui->lineEdit->clear();
    ui->listofmessages->clear();


}

void contentsearch::on_pushButton_3_clicked()
{
    homepage *picbacktohomepage;
    this->close();
    picbacktohomepage = new homepage(this->GetObject(), this);
    picbacktohomepage->show();
}

void contentsearch::on_pushButton_clicked()
{
    ui->listofmessages->sortItems(Qt::AscendingOrder);



}

void contentsearch::on_pushButton_2_clicked()
{
    ui->listofmessages->sortItems(Qt::DescendingOrder);

}
