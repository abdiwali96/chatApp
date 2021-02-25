#include "contentsearch.h"
#include "ui_contentsearch.h"
#include "homepage.h"

contentsearch::contentsearch(User* User1,User* User2, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::contentsearch)
{
    ui->setupUi(this);

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
    //
   ui->listofmessages->clear();
   QString searchphrase = ui->SearchBox->text();

   QSqlQuery queryH(QSqlDatabase::database("QMYSQL"));
   queryH.prepare(QString("SELECT * FROM ChatLogs WHERE User1log = :User1log OR User2log = :User2log"));

   queryH.bindValue(":User1log",this->GetObject()->getUsername());
   queryH.bindValue(":User2log",this->GetObject()->getUsername());

   queryH.exec();

  while(queryH.next()){
      QString dbmessage = queryH.value(5).toString();
      QStringList fl = dbmessage.split(",");

      for ( const auto& i : fl)
      {
          qDebug() << i;
          QString elementMessage = i;
          if (i.contains(ui->SearchBox->text())){


          ui->listofmessages->addItem(elementMessage);

          }

      }

  }


}

void contentsearch::on_editselect_clicked()
{

}
