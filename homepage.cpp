#include "homepage.h"
#include "ui_homepage.h"
#include "login.h"
#include "user.h"

#include <QList>
#include <QStringList>
#include <QVector>

using namespace std;


homepage::homepage(User* User1,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::homepage)
{
    this->setFixedSize(1100,800);
    this->User1 = User1 ;
    ui->setupUi(this);
    ui->User1_Username->setText(this->User1->getUsername());
    ui->User1_Email->setText(this->User1->getEmail());
    ui->User1_Mobile->setText(this->User1->getMobile());
    ui->ProfilePic->setPixmap(this->User1->getProfilepic().scaled (250,170));
    ProfileSetup();
    friendsetup();

}

homepage::~homepage()
{
    delete ui;
}

void homepage::friendsetup(){
    ui->listoffriends->clear();

    QSqlQuery query(QSqlDatabase::database("QMYSQL"));
    QString delimiter = ",";
    QStringList fl = User1->getFriendslist().split(",");
    QVector<int> friendsIdList;
    QStringList friendID;
    QStringList friendUsernames  ;

    QList<QPixmap> piclist;

    for(QString number :fl){
        friendsIdList.append(number.toInt());
    }

    QStringList FriendUsernamelist ;

    for (int x : friendsIdList)
    {
        query.prepare(QString("SELECT * FROM members WHERE id = :userid"));
        query.bindValue(":userid",x);

        query.exec();

        while(query.next()){
        QString friendID = query.value(0).toString();
        QString friendusernamerow = query.value(1).toString();

        friendID.append(friendID);
        friendUsernames.append(friendusernamerow);


        QByteArray PictureFromDatabase = query.value(5).toByteArray();
        QPixmap friendavatar = QPixmap();
        friendavatar.loadFromData(PictureFromDatabase);
        piclist.append(friendavatar);

      }
    }

        for (int i = 0; i < friendUsernames.count(); i++) {
            QListWidgetItem *item  = new QListWidgetItem(piclist[i],friendUsernames[i]);
            ui->listoffriends->addItem(item);

    }
     this->friendUsernames = friendUsernames ;

     getNumerofMess();
     getNumofMes24hrs();
     getNumofAttach();
     ui->label_14->setText(QString::number(ui->listoffriends->count()) + " Friends");
     getFirstMessDate();
}

void homepage::ProfileSetup(){

    QSqlQuery query1(QSqlDatabase::database("QMYSQL"));
    query1.prepare(QString("SELECT * FROM members WHERE username = :username"));

    query1.bindValue(":username",this->User1->getUsername());
    query1.exec();

}

void homepage::on_ViewHistory_clicked()
{
    if(ui->SearchBox->text().isEmpty()){
         QMessageBox::information(this,"SORRY","YOU NEED TO FIRST ENTER OR SELECT A USERNAME");
    }else{
        createTopic();
        this->hide();
        QString Username1 = this->User1->getUsername();
        QString Username2 = User2->getUsername();

         historyapp = new historyappwindow(User1,User2,this->Topic, this);
         historyapp ->show();
    }

}

void homepage::on_ViewAllHistory_clicked()
{
    this->hide();
    User2 = new User("","","", "", QPixmap(":/images/emptyprofilepic.png"), "");
    historyapp = new historyappwindow(User1,User2,"", this);
    historyapp ->show();
}


void homepage::on_EditProfilePic_clicked(){

    this->hide();
    uploadpicwindow = new uploadpic(User1,this);
    uploadpicwindow->show();

}

void homepage::on_EditProfilebutton_clicked()
{
    this->hide();
    editprofilecwindow = new Editprofile(User1,this);
    editprofilecwindow->show();
}

void homepage::on_Searchbutton_clicked()
{
    QString Searchmember = ui->SearchBox->text();
    QSqlQuery query1(QSqlDatabase::database("QMYSQL"));
    query1.prepare(QString("SELECT * FROM members WHERE username = :username"));

    query1.bindValue(":username",Searchmember);
    query1.exec();

    if(query1.next()){

        QString User2_ID = query1.value(0).toString();
        QString User2_Username = query1.value(1).toString();
        QString User2_Email = query1.value(3).toString();
        QString User2_Mobile = query1.value(4).toString();
        //AVATAR
        QByteArray PictureFromDatabase2 =query1.value(5).toByteArray();
        QPixmap User1_Profile2 = QPixmap();
        User1_Profile2.loadFromData(PictureFromDatabase2);

        //FriendsID
        QString User2_friendslistnum = query1.value(6).toString();
        User2 = new User(User2_ID,User2_Username,User2_Email, User2_Mobile, User1_Profile2, User2_friendslistnum);

      QMessageBox::information(this,"Success","FOUND USER");
      ui->searchusernameresult->setText(User2->getUsername());
      ui->searchemailresult->setText(User2->getEmail());
    }else {
         QMessageBox::information(this,"SORRY","NO USER FOUND");
    }
}

void homepage::on_Addfriend_clicked()
{
    if(ui->SearchBox->text().isEmpty()){
         QMessageBox::information(this,"SORRY","YOU NEED TO FIRST ENTER OR SELECT A USERNAME");
    }else {
        bool found = (std::find(this->friendUsernames.begin(), this->friendUsernames.end(), User2->getUsername()) != this->friendUsernames.end());

        if (found){
              QMessageBox::information(this,"SORRY","USER IS ALREADY A FRIEND");
        }else {
            QMessageBox::information(this,"DONE","USER IS ADDED TO YOUR FRIENDS LIST");

            QSqlQuery query1(QSqlDatabase::database("QMYSQL"));
            query1.prepare("UPDATE members SET Numberoffriends = :Numberoffriends WHERE username = :username");
            query1.bindValue(":username",User1->getUsername());

            query1.bindValue(":Numberoffriends",User1->getFriendslist() + "," +User2->getId());
            query1.exec();


            User1->setFriendslist(User1->getFriendslist() + "," + User2->getId());
            ProfileSetup();
            friendsetup();
        }

    }

}

void homepage::createTopic()
{
    // Algortihm to create Topic for USER1 to USER 2
    QString Topic;
    int FristTopic = User1->getId().toInt() ;
    int SecondTopic = User2->getId().toInt();

    if (FristTopic > SecondTopic){
        Topic = User1->getUsername() + "2" + User2->getUsername() ;
    }else {
       Topic = User2->getUsername() + "2" + User1->getUsername() ;
    }
   this->Topic = Topic;
}

void homepage::on_SendMessage_clicked()
{
    if(ui->SearchBox->text().isEmpty()){
         QMessageBox::information(this,"SORRY","YOU NEED TO FIRST ENTER OR SELECT A USERNAME");
    }else{
        createTopic();
        this->hide();
        QString Username1 = this->User1->getUsername();
        QString Username2 = User2->getUsername();
        mainwindowchat = new MainWindow(User1,User2,this->Topic, this);
        mainwindowchat->show();
    }
}


void homepage::on_listoffriends_itemClicked()
{
    QString SelectedFilename = ui->listoffriends->currentItem()->text();
    ui->SearchBox->setText(SelectedFilename);
}


void homepage::on_pushButton_clicked()
{
    this->hide();
    User2 = new User("","","", "", QPixmap(":/images/emptyprofilepic.png"), "");
    contentsearchwindow = new contentsearch(User1,User2, this);
    contentsearchwindow->show();

}

void homepage::getNumerofMess() {

    QSqlQuery queryH(QSqlDatabase::database("QMYSQL"));
    queryH.prepare(QString("SELECT * FROM ChatLogs WHERE User1log = :User1log"));

    queryH.bindValue(":User1log",this->User1->getUsername());
    queryH.exec();
    int countnum = 0;

    while(queryH.next()){
        countnum++;
    }
    ui->nummessagelabel->setText(QString::number(countnum) + " Messages");
}

void homepage::getNumofMes24hrs(){

    QDateTime dateTime = dateTime.currentDateTime();
    QString dateTimeString = dateTime.toString("yyyy-MM-dd");

    QSqlQuery queryH(QSqlDatabase::database("QMYSQL"));
    queryH.prepare(QString("SELECT * FROM ChatLogs WHERE User1log = :User1log "));
    queryH.bindValue(":User1log",this->User1->getUsername());
    queryH.exec();
    int countnum = 0;

    while(queryH.next()){
        if(queryH.value(4).toString().contains(dateTimeString)){
            countnum++;
        }
    }

    ui->label_11->setText(QString::number(countnum) + " Messages");
}
void homepage::getNumofAttach(){

    QSqlQuery queryH(QSqlDatabase::database("QMYSQL"));
    queryH.prepare(QString("SELECT * FROM attachedfiles"));
    queryH.exec();
    int countnum = 0;
    while(queryH.next()){

        if(queryH.value(4).toString().contains(this->User1->getUsername())){
            countnum++;
        }
    }

    ui->label_13->setText(QString::number(countnum) + " Files");
}

void homepage::getFirstMessDate(){
    QSqlQuery queryH(QSqlDatabase::database("QMYSQL"));
    queryH.prepare(QString("SELECT * FROM ChatLogs WHERE User1log = :User1log "));
    queryH.bindValue(":User1log",this->User1->getUsername());
    queryH.exec();

     if(queryH.first()){

          QString delimiter = "_";
          QStringList datessplit = queryH.value(4).toString().split("_");
           ui->label_16->setText(datessplit.first());
     }
}
