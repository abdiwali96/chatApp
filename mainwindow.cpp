#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QtCore/QDateTime>
#include <QtMqtt/QMqttClient>
#include <QtWidgets/QMessageBox>

#include "login.h"
MainWindow::MainWindow(User* User1,User* User2,QString Topic, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->chatobject = new chat();
    this->User1 = User1 ;
    this->User2 = User2 ;

    //make a query in database to set the values , dont forget date
    this->chatobject->setuser1(this->GetObject()->getUsername());
    this->chatobject->setuser2(this->GetObject2()->getUsername());
    this->chatobject->setttopicname(Topic);

    QDateTime dateTime = dateTime.currentDateTime();
    QString dateTimeString = dateTime.toString("yyyy-MM-dd_hh-mm-ss");

    this->chatobject->setdate(dateTimeString);
    this->chatobject->setmessage({});
    this->chatobject->addTOmessage("");


   // QString str = this->chatobject->getmessage().join(",");

    this->setFixedSize(1116,885);
    ui->setupUi(this);
    QStringList MessageLogging ;


    ui->User1name->setText(this->chatobject->getuser1());
    ui->User2name->setText(this->chatobject->getuser2());
    ui->Topicname->setText(this->chatobject->gettopicname());

   //this->User1 = User1;
    //this->User2 = User2;
    //this->Topicname = Topicname;
    GetEmojis();


    m_client = new QMqttClient(this);

    m_client->setHostname("127.0. 0.1");
    m_client->setPort(1883);
   // m_client->setHostname(ui->lineEditHost->text());
   // m_client->setPort(ui->spinBoxPort->value());

    connect(m_client, &QMqttClient::stateChanged, this, &MainWindow::updateLogStateChange);
    connect(m_client, &QMqttClient::disconnected, this, &MainWindow::brokerDisconnected);

    connect(m_client, &QMqttClient::messageReceived, this, [this](const QByteArray &message, const QMqttTopicName &topic) {
        const QString content = QDateTime::currentDateTime().toString()
                    + QLatin1String(" Received Topic: ")
                    + topic.name()
                    + QLatin1String(" Message: ")
                    + message
                    + QLatin1Char('\n');
        ui->editLog->insertPlainText(content);
        //adding it to list
        this->chatobject->addTOmessage(content + ".,");


    });

    connect(m_client, &QMqttClient::pingResponseReceived, this, [this]() {
        const QString content = QDateTime::currentDateTime().toString()
                    + QLatin1String(" PingResponse")
                    + QLatin1Char('\n');
        ui->editLog->insertPlainText(content);

    });

   // connect(ui->lineEditHost, &QLineEdit::textChanged, m_client, &QMqttClient::setHostname);
   // connect(ui->spinBoxPort, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::setClientPort);
    updateLogStateChange();
}

MainWindow::~MainWindow()
{
    delete ui;
}

User* MainWindow::GetObject(){
    return User1 ;
}

void MainWindow::SetObject(QString s) {
      User1->setUsername(s);
}

User* MainWindow::GetObject2(){
    return User2;
}

void MainWindow::SetObject2(QString s) {
      User2->setUsername(s);
}

void MainWindow::on_buttonConnect_clicked()
{
    if (m_client->state() == QMqttClient::Disconnected) {
       // ui->lineEditHost->setEnabled(false);
       // ui->spinBoxPort->setEnabled(false);
      //  ui->buttonConnect->setText(tr("Disconnect"));
        m_client->connectToHost();
    } else {
     //  ui->lineEditHost->setEnabled(true);
      // ui->spinBoxPort->setEnabled(true);
        ui->buttonConnect->setText(tr("Connect"));
        m_client->disconnectFromHost();
    }
}

void MainWindow::on_buttonQuit_clicked()
{
    QApplication::quit();
}

void MainWindow::updateLogStateChange()
{
    const QString content = QDateTime::currentDateTime().toString()
                    + QLatin1String(": State Change")
                    + QString::number(m_client->state())
                    + QLatin1Char('\n');
    ui->editLog->insertPlainText(content);

}

void MainWindow::brokerDisconnected()
{
  //  ui->lineEditHost->setEnabled(true);
  //  ui->spinBoxPort->setEnabled(true);
    ui->buttonConnect->setText(tr("Connect"));
}

void MainWindow::setClientPort(int p)
{
    m_client->setPort(p);
}

void MainWindow::on_buttonPublish_clicked()
{
    if (m_client->publish(this->chatobject->gettopicname(), ui->lineEditMessage->text().toUtf8()) == -1)
        QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not publish message"));

}

void MainWindow::on_buttonSubscribe_clicked()
{
    auto subscription = m_client->subscribe(this->chatobject->gettopicname());

    if (!subscription) {
        QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not subscribe. Is there a valid connection?"));
        return;
    }
    //updates ran
    GetMessageHistory();

}

void MainWindow::GetEmojis(){

        ui->Emojiwidget->setFlow(QListView::LeftToRight);
        QStringList *emojiS = new QStringList;

        emojiS->append("👍");
        emojiS->append("👍");
        emojiS->append("👎");
        emojiS->append("💪");
        emojiS->append("💪");
        emojiS->append("🧳");
        emojiS->append("🌂");
        emojiS->append("🧵");
        emojiS->append("😂");
        emojiS->append("🙂");
        emojiS->append("😞");
        emojiS->append("🕶");
        emojiS->append("🦺");
        emojiS->append("👋🏻");



        for (int i=0; i<emojiS->length(); i++)
           {
            //QListWidgetItem *qlwi = new QListWidgetItem;
            //qlwi->setText(qsl->at(i));
            ui->Emojiwidget->addItem(emojiS->at(i));
           }

}

void MainWindow::on_Uploadfile_clicked()
{
    QString uploadfilename;
    QByteArray byte0;
    uploadfilename = QFileDialog::getOpenFileName(this,tr("Open "), "",tr("File (*)"));


     this->uploadfilename = uploadfilename;

    if(QString::compare(uploadfilename, QString()) != 0){
        //QFile file(uploadfilename);
        //happens

        QFile file(uploadfilename);
        byte0 = file.readAll();

        if(file.open(QIODevice::ReadOnly))
            {
                byte0 = file.readAll();
                file.close();

            }

          // cout << byte0.toStdString() << endl;



        //ui->label_7->setText(itm->text());

        QSqlQuery qry(QSqlDatabase::database("QMYSQL"));

        qry.prepare("INSERT INTO attachedfiles (filesave,chatLogID,filename,Topicname)"
                    "VALUES (:filesave,:chatLogID,:filename,:Topicname)");

// CHANGE THE 121 number to LOGID
        qry.bindValue(":filesave", byte0 , QSql::In | QSql::Binary);
        qry.bindValue(":chatLogID",this->chatobject->getOldchatlogid());
        qry.bindValue(":filename",uploadfilename);
        qry.bindValue(":Topicname",this->chatobject->gettopicname());


        if(qry.exec()){

            if (m_client->publish(this->chatobject->gettopicname(), "NOTE:FILE HAS BEEN UPLOADED, PLEASE REFRESH 📦➡️") == -1)

            ui->editLog->insertPlainText("NOTE:FILE HAS BEEN UPLOADED, PLEASE REFRESH 📦➡️" );

            QMessageBox::information(this, "Inserted", "Data is Inserted Succesfully");
        }else {
            QMessageBox::information(this, "NOT Inserted", "Data is NOT Inserted Succesfully");
        }

    }

    GetListUpdate();

}

void MainWindow::GetMessageHistory(){


    // HAVE AN IF STATEMENT
    QSqlQuery queryH(QSqlDatabase::database("QMYSQL"));
    queryH.prepare(QString("SELECT * FROM ChatLogs WHERE Topicname = :Topicname"));

    queryH.bindValue(":Topicname",this->chatobject->gettopicname());
    //condition below is if condition fails to execute
    queryH.exec();
     while(queryH.next()){

        // int dbmessage1 = queryH.value(0).toInt();
          // qDebug() << dbmessage1;
         this->chatobject->setOldchatlogid(queryH.value(0).toInt()+1);

          QString dbmessage = queryH.value(5).toString();
          QStringList fl = dbmessage.split(",");

          qDebug() << fl;
          for ( const auto& i : fl )
          {
              qDebug() << i;
              QString elementMessage = i;

              ui->editLog->insertPlainText(elementMessage);

          }

     }

}

void MainWindow::GetListUpdate(){

    ui->Attachmentview->clear();

    QSqlQuery query1(QSqlDatabase::database("QMYSQL"));
    query1.prepare(QString("SELECT * FROM attachedfiles WHERE Topicname = :Topicname"));

    //query1.bindValue(":chatLogID",this->chatobject->getOldchatlogid());
    query1.bindValue(":Topicname", this->chatobject->gettopicname());

    //results of the query

    //condition below is if condition fails to execute
    query1.exec();


    while (query1.next()) {

        QListWidgetItem *item  = new QListWidgetItem(QIcon(":/images/foldericon.png"),query1.value(3).toString());


        ui->Attachmentview->addItem(item);
    }

    /*
    QListWidgetItem *itm =  new QListWidgetItem(uploadfilename);
    ui->Attachmentview->addItem(uploadfilename);
    */

}
void MainWindow::on_OpenAttachment_clicked()
{
    //
     QMessageBox::information(this, "Inserted", ui->Attachmentview->currentItem()->text());

     QString SelectedFilename = ui->Attachmentview->currentItem()->text();
     QSqlQuery query3(QSqlDatabase::database("QMYSQL"));
     //query3.prepare(QString("SELECT * FROM attachedfiles WHERE chatLogID = :chatLogID AND filename = :filename"));

     query3.prepare(QString("SELECT * FROM attachedfiles WHERE Topicname = :Topicname AND filename = :filename"));

     query3.bindValue(":Topicname", this->chatobject->gettopicname());
     query3.bindValue(":filename",SelectedFilename);
     query3.exec();

         if(query3.next()){


             QByteArray fileFromDatabase = query3.value(1).toByteArray();

             QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                         "",tr("File (*)"));

             QSaveFile file(fileName);


             file.open(QIODevice::WriteOnly);
             file.write(fileFromDatabase);

             file.commit();
             QMessageBox::information(this, "SAVED SUCCESSFUL", "File is Save at the location! Enjoy :)");



          }else{
              QMessageBox::information(this, "Inserted", "not found");
         }

}

void MainWindow::on_Emojiwidget_itemClicked(QListWidgetItem *item)
{
    QString s = item->text();
    ui->lineEditMessage->insert(s);
}

void MainWindow::on_returnhome_clicked()
{
    // upload to database the chat log


    QSqlQuery qry(QSqlDatabase::database("QMYSQL"));

    qry.prepare("INSERT INTO ChatLogs (Topicname, User1log, User2log, Date, Message)"
                "VALUES (:Topicname, :User1log, :User2log, :Date, :Message)");

    qry.bindValue(":Topicname", this->chatobject->gettopicname());
    qry.bindValue(":User1log", this->chatobject->getuser1());
    qry.bindValue(":User2log", this->chatobject->getuser2());
    qry.bindValue(":Date", this->chatobject->getdate());
    qry.bindValue(":Message",this->chatobject->getmessage().join(""));

    if(qry.exec()){

        QMessageBox::information(this, "Save", "Your Chat is Saved!");

    }else {
        QMessageBox::information(this, "NOT Saved", "Not saved chat");
    }


    homepage *picbacktohomepage;
    this->close();
    picbacktohomepage = new homepage(this->GetObject(), this);
    picbacktohomepage->show();



}

void MainWindow::on_refreshattachments_clicked()
{
    //update list
    GetListUpdate();
}
