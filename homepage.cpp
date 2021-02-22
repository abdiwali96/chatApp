#include "homepage.h"
#include "ui_homepage.h"
#include "login.h"
#include "user.h"

#include <QList>
#include <QStringList>
#include <QVector>


using namespace std;



//i ve added to this first part parmaerter
homepage::homepage(User* User1,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::homepage)
{
    this->setFixedSize(1100,800);
    this->User1 = User1 ;

    LogginUser = "testing";
    ui->setupUi(this);
    //label
    ui->User1_Username->setText(this->User1->getUsername());
    ui->User1_Email->setText(this->User1->getEmail());
    ui->User1_Mobile->setText(this->User1->getMobile());

    ui->ProfilePic->setPixmap(this->User1->getProfilepic().scaled (265,235,Qt::KeepAspectRatio));
   // ProfileSetup();
    friendsetup();

}

homepage::~homepage()
{
    delete ui;
}

void homepage::friendsetup(){

     QSqlQuery query(QSqlDatabase::database("QMYSQL"));
    //ui->label_9->setText(User1->friendslist);


    QString delimiter = ",";
    QStringList fl = User1->getFriendslist().split(",");


    QVector<int> friendsIdList;
    QStringList friendID;
    QStringList friendUsernames  ;



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
        // ui->listoffriends->addItem(friendUsernames);
        }

      }

    foreach(QString i, friendUsernames) {

        ui->listoffriends->addItem(i);

    }
     this->friendUsernames = friendUsernames ;


  // QString s = ui->listoffriends->currentItem()->text();
  // cout <<  << endl;

}

void homepage::ProfileSetup(){


//
}



void homepage::on_EditProfilePic_clicked(){

    this->hide();
    //QString SendOverUsername = LogginUser;

    uploadpicwindow = new uploadpic(User1,this);

    uploadpicwindow->show();

}

void homepage::on_EditProfilebutton_clicked()
{
    this->hide();
    //QString SendOverUsername = LogginUser;

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
        //QString User1_UfriendsIdListsername = query.value(1).toString();
        QString User2_Email = query1.value(3).toString();
        QString User2_Mobile = query1.value(4).toString();

        //AVATAR
        QByteArray PictureFromDatabase2 =query1.value(5).toByteArray();
        QPixmap User1_Profile2 = QPixmap();
        User1_Profile2.loadFromData(PictureFromDatabase2);

        //FriendsID
        QString User2_friendslistnum = query1.value(6).toString();

        //this->userobject2->setId(User2_ID);
       // this->userobject2->setUsername(User2_Username);
        //this->userobject2->setEmail(User2_Email);
        //this->userobject2->setMobile(User2_Mobile);
        //this->userobject2->setProfilepic(User1_Profile2);
        //this->userobject2->setFriendslist(User2_friendslistnum);

        User2 = new User(User2_ID,User2_Username,User2_Email, User2_Mobile, User1_Profile2, User2_friendslistnum);


      QMessageBox::information(this,"Success","FOUND USER");
      ui->searchusernameresult->setText(User2->getUsername());
      ui->searchemailresult->setText(User2->getEmail());


      }


}

void homepage::on_Addfriend_clicked()
{

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



    }
    ui->listoffriends->clear();
    ProfileSetup();
    friendsetup();


}

void homepage::createTopic()
{
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
    createTopic();
    this->hide();
    //Qtring Username1 = LogginUser;
    QString Username1 = User1->getUsername();
    QString Username2 = User2->getUsername();
    //QString FT = Topic ;

    mainwindowchat = new MainWindow(User1,User2,this->Topic, this);

    mainwindowchat->show();

}



void homepage::on_listoffriends_itemClicked()
{
    QString SelectedFilename = ui->listoffriends->currentItem()->text();
    ui->SearchBox->setText(SelectedFilename);
}
