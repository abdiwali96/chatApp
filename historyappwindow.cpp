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
    ui->SearchBox->setText(this->Topic);
     this->chatobject->setttopicname(this->Topic);

    ui->checkBox->setText("Has Attachment \n Conent");


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

   qDebug() << this->chatobject->gettopicname();




    ui->listofmessages->clear();

    // HAVE AN IF STATEMENT
    QSqlQuery querya(QSqlDatabase::database("QMYSQL"));
    querya.prepare(QString("SELECT * FROM ChatLogs WHERE Topicname = :Topicname OR User1log = :User1log AND User2log = :me or User1log = :me AND User2log = :User2log "));

    querya.bindValue(":Topicname",this->chatobject->gettopicname());
    querya.bindValue(":User1log",this->chatobject->gettopicname());
    querya.bindValue(":User2log",this->chatobject->gettopicname());
    querya.bindValue(":me",this->User1->getUsername());
    //condition below is if condition fails to execute
    querya.exec();
     while(querya.next()){

        // int dbmessage1 = queryH.value(0).toInt();
          // qDebug() << dbmessage1;
        // this->chatobject->setOldchatlogid(queryH.value(0).toInt());
         //int dbchatlogID = queryH.value(0).toInt();
         QString StrdbcahtlogID = querya.value(0).toString();
         QString dbmessagetopic = querya.value(1).toString();
         QString dbmessagedate = querya.value(4).toString();

         this->dbmessage = querya.value(5).toString();


          ui->listofmessages->addItem(StrdbcahtlogID + ", | Topic:" +dbmessagetopic + " | Date: "+ dbmessagedate);


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
