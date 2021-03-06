#ifndef HOMEPAGE_H
#define HOMEPAGE_H


#include <QMainWindow>

#include "uploadpic.h"
#include "editprofile.h"
#include "mainwindow.h"
#include "historyappwindow.h"
#include "contentsearch.h"
namespace Ui {
class homepage;
}


class homepage : public QMainWindow
{
    Q_OBJECT

public:

    explicit homepage(User* User1,QWidget *parent = nullptr);

    ~homepage();

    void friendsetup();

    void createTopic();

    void ProfileSetup();

    void getNumerofMess();

    void getNumofMes24hrs();

    void getNumofAttach();

    void getFirstMessDate();

    QString Topic;

    QString delimiter;

    QStringList fl ;
    QStringList friendID;
    QStringList friendUsernames;
    QVector<int> friendsIdList;
    QString friendusername;
    QList<QPixmap> piclist;


private slots:

    void on_EditProfilePic_clicked();

    void on_EditProfilebutton_clicked();

    void on_Searchbutton_clicked();

    void on_Addfriend_clicked();

    void on_SendMessage_clicked();

    void on_listoffriends_itemClicked();

    void on_ViewHistory_clicked();

    void on_pushButton_clicked();

    void on_ViewAllHistory_clicked();

private:
    Ui::homepage *ui;

    User *User1;
    User *User2;

     QString LogginUser;

     historyappwindow *historyapp;
     contentsearch *contentsearchwindow;
     Editprofile *editprofilecwindow;
     uploadpic *uploadpicwindow;
     MainWindow *mainwindowchat;

};

#endif // HOMEPAGE_H
