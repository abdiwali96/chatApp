#ifndef HOMEPAGE_H
#define HOMEPAGE_H


#include <QMainWindow>
#include "user.h"
#include "databaseconnection.h"
#include "uploadpic.h"
#include "editprofile.h"
#include "mainwindow.h"

namespace Ui {
class homepage;
}

class homepage : public QMainWindow
{
    Q_OBJECT

public:
    //i added first part of parameter
    explicit homepage(QString text,QWidget *parent = nullptr);
    ~homepage();

    void friendsetup();

    void createTopic();

    void ProfileSetup();


    QString Topic;


    User *User1;
    User *User2;
    /*
    QString User1_ID;
    QString User1_Username;
    QString User1_Email ;
    QString User1_Mobile ;
    QString User1_friendslistnum;
    */

    QString delimiter;

    QStringList fl ;
    QStringList friendID;
    QStringList friendUsernames;
    QVector<int> friendsIdList;
    QString friendusername;




private slots:



    void on_EditProfilePic_clicked();

    void on_EditProfilebutton_clicked();

    void on_Searchbutton_clicked();

    void on_Addfriend_clicked();

    void on_SendMessage_clicked();



private:
    Ui::homepage *ui;

    //I added below
     QString LogginUser;

     //
      Editprofile *editprofilecwindow;
      uploadpic *uploadpicwindow;
      MainWindow *mainwindowchat;

};

#endif // HOMEPAGE_H
