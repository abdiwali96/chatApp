#include "historyappwindow.h"
#include "ui_historyappwindow.h"

historyappwindow::historyappwindow(User* User1,User* User2,QString Topic, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::historyappwindow)
{
    ui->setupUi(this);
    this->chatobject = new chat();
    this->User1 = User1 ;
    this->User2 = User2 ;
    this->Topic = Topic;
    this->chatobject->setmessage({});
    this->chatobject->addTOmessage("");
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

QString historyappwindow::GetTopic(){
      return Topic;
}

void historyappwindow::GetMessageHistory(){

    ui->listofmessages->clear();

    // HAVE AN IF STATEMENT
    QSqlQuery queryH(QSqlDatabase::database("QMYSQL"));
    queryH.prepare(QString("SELECT * FROM ChatLogs WHERE Topicname = :Topicname"));

    queryH.bindValue(":Topicname",this->GetTopic());
    //condition below is if condition fails to execute
    queryH.exec();
     while(queryH.next()){

        // int dbmessage1 = queryH.value(0).toInt();
          // qDebug() << dbmessage1;
        // this->chatobject->setOldchatlogid(queryH.value(0).toInt());
         int dbchatlogID = queryH.value(0).toInt();
         QString StrdbcahtlogID = queryH.value(0).toString();
         QString dbmessagetopic = queryH.value(1).toString();
         QString dbmessagedate = queryH.value(3).toString();

         this->dbmessage = queryH.value(5).toString();

          ui->listofmessages->addItem(StrdbcahtlogID + ", | Topic:" +dbmessagetopic + " | Date: "+ dbmessagedate);


     }
}

void historyappwindow::searchRescord(){
    /*

     */
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
        QString dbmessage = queryH.value(5).toString();
        QStringList fl = dbmessage.split(",");

        for ( const auto& i : fl)
        {
            qDebug() << i;
            QString elementMessage = i;

            ui->editLog1->insertPlainText(elementMessage);

        }
    }



}
