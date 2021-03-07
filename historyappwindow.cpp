#include "historyappwindow.h"
#include "ui_historyappwindow.h"
#include "homepage.h"

historyappwindow::historyappwindow(User* User1,User* User2,QString Topic, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::historyappwindow)
{
    ui->setupUi(this);
    this->setFixedSize(1108,833);
    this->chatobject = new chat();
    this->User1 = User1 ;
    this->User2 = User2 ;
    this->Topic = Topic;
    this->chatobject->setmessage({});
    this->chatobject->addTOmessage("");
    ui->SearchBox->setText(this->Topic);
     this->chatobject->setttopicname(this->Topic);

    ui->checkBox->setText(" Only Has \n Attachment Conent");
    GetMessageHistory();

}

historyappwindow::~historyappwindow()
{
    delete ui;
}

User* historyappwindow::GetObject(){
    return User1 ;
}

void historyappwindow::SetObject(QString s) {
      User1->setUsername(s);
}

User* historyappwindow::GetObject2(){
    return User2;
}

void historyappwindow::SetObject2(QString s) {
      User2->setUsername(s);
}



void historyappwindow::GetMessageHistory(){

    this->chatobject->setttopicname(ui->SearchBox->text());
   //qDebug() << this->chatobject->gettopicname();
    ui->listofmessages->clear();

    QSqlQuery querya(QSqlDatabase::database("QMYSQL"));
    querya.prepare(QString("SELECT * FROM ChatLogs WHERE Topicname = :Topicname AND User1log = :me OR Topicname = :Topicname AND User2log = :me OR User1log = :me AND User2log = :User2log OR User1log = :User1log AND User2log = :me"));

    querya.bindValue(":Topicname",this->chatobject->gettopicname());
     querya.bindValue(":User1log",this->chatobject->gettopicname());
    querya.bindValue(":User2log",this->chatobject->gettopicname());
    querya.bindValue(":me",this->User1->getUsername());


    //condition below is if condition fails to execute
    querya.exec();
     while(querya.next()){


         QString StrdbcahtlogID = querya.value(0).toString();
         int chid = querya.value(0).toInt();
         QString dbmessagetopic = querya.value(1).toString();
         QString dbmessagedate = querya.value(4).toString();

         this->dbmessage = querya.value(5).toString();

         if(ui->checkBox->isChecked()){
             QSqlQuery querya1(QSqlDatabase::database("QMYSQL"));
             querya1.prepare(QString("SELECT * FROM attachedfiles WHERE chatLogID = :chatLogID"));
             querya1.bindValue(":chatLogID",chid);

             querya1.exec();
             while(querya1.next()){
             ui->listofmessages->addItem(StrdbcahtlogID + ", | Topic:" +dbmessagetopic + " | Date: "+ dbmessagedate);
             }
         } else{


          ui->listofmessages->addItem(StrdbcahtlogID + ", | Topic:" +dbmessagetopic + " | Date: "+ dbmessagedate);
         }





     }
}

void historyappwindow::searchRescord(){
    /*

     */
}

void historyappwindow::Query(){
    ui->listofmessages->clear();

}



void historyappwindow::on_OpenAttachment_clicked()
{
    ui->editLog1->clear();

    QStringList WidgetMessage =  ui->listofmessages->currentItem()->text().split(",");

   int chatidnum = WidgetMessage.front().toInt();
     qDebug() <<  chatidnum;
    ui->listofmessages->currentItem()->text();

    QSqlQuery queryH(QSqlDatabase::database("QMYSQL"));
    queryH.prepare(QString("SELECT * FROM ChatLogs WHERE chatLogID = :chatLogID"));

    queryH.bindValue(":chatLogID",chatidnum);

    queryH.exec();

   while(queryH.next()){
        this->dbmessage = queryH.value(5).toString();
        QStringList fl = this->dbmessage .split(",");

        for ( const auto& i : fl)
        {
            qDebug() << i;
            QString elementMessage = i;

            ui->editLog1->insertPlainText(elementMessage);

        }
    }



}

void historyappwindow::on_pushButton_2_clicked()
{
      ui->listofmessages->sortItems(Qt::DescendingOrder);

}

void historyappwindow::on_pushButton_clicked()
{
     ui->listofmessages->sortItems(Qt::AscendingOrder);
}

void historyappwindow::on_Searchbutton_clicked()
{

    GetMessageHistory();
}

void historyappwindow::on_deletemessagebtn_clicked()
{
    QStringList WidgetMessage =  ui->listofmessages->currentItem()->text().split(",");

   int chatidnum = WidgetMessage.front().toInt();
     qDebug() <<  chatidnum;
    ui->listofmessages->currentItem()->text();

    QSqlQuery queryH(QSqlDatabase::database("QMYSQL"));
    queryH.prepare(QString("DELETE FROM ChatLogs WHERE chatLogID = :chatLogID"));

    queryH.bindValue(":chatLogID",chatidnum);

    queryH.exec();

   while(queryH.next()){

       QMessageBox::information(this, "DELETE", "MESSAGE IS DELETED!");
    }
   GetMessageHistory();
}

void historyappwindow::on_pushButton_3_clicked()
{
    homepage *picbacktohomepage;
    this->close();
    picbacktohomepage = new homepage(this->GetObject(), this);
    picbacktohomepage->show();
}

void historyappwindow::on_pushButton_4_clicked()
{
   ui->editLog1->insertPlainText("\n A NEW EDIT ADDED:" + ui->lineEdit->text());

   QStringList WidgetMessage =  ui->listofmessages->currentItem()->text().split(",");

  int chatidnum = WidgetMessage.front().toInt();

   QSqlQuery queryH(QSqlDatabase::database("QMYSQL"));
   this->dbmessage.append(".," + ui->lineEdit->text());

  queryH.prepare("UPDATE ChatLogs SET Message = :Message WHERE chatLogID = :chatLogID");
   queryH.bindValue(":chatLogID",chatidnum);
  queryH.bindValue(":Message", this->dbmessage );

   queryH.exec();

}
