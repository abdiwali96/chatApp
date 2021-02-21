#ifndef USER_H
#define USER_H
#include <string>
#include<iostream>
#include <QMainWindow>
#include <QVector>
#include <QPixmap>
#include <QByteArray>
#include<QDebug>
#include <string>

using namespace std;

class User {       // The class
  public:
    //User();
    User(QString idnum, QString usernamenum, QString email, QString mobilenum, QPixmap profilepicnum, QString friendslistnum);
/*
    int id;
    QString username;
    QString email;
    QString mobile;
    QPixmap profilepic;
    QString friendslist;
*/

    void setId(QString s) ;
    void setUsername(QString s);
    void setEmail(QString s) ;
    void setMobile(QString s) ;
    void setProfilepic(QPixmap s);
    void setFriendslist(QString s);


    QString getId() ;
    QString getUsername();
    QString getEmail() ;
    QString getMobile() ;
    QPixmap getProfilepic();
    QString getFriendslist();

private:

    QString id;
    QString username;
    QString email;
    QString mobile;
    QPixmap profilepic;
    QString friendslist;

};





#endif // USER_H
