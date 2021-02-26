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

/**
 * @brief
 *
 */
class User {       // The class
  public:
    //User();
    /**
     * @brief
     *
     * @param idnum
     * @param usernamenum
     * @param email
     * @param mobilenum
     * @param profilepicnum
     * @param friendslistnum
     */
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
    /**
     * @brief
     *
     * @param s
     */
    void setEmail(QString s) ;
    /**
     * @brief
     *
     * @param s
     */
    void setMobile(QString s) ;
    /**
     * @brief
     *
     * @param s
     */
    void setProfilepic(QPixmap s);
    /**
     * @brief
     *
     * @param s
     */
    void setFriendslist(QString s);


    /**
     * @brief
     *
     * @return QString
     */
    QString getId() ;
    /**
     * @brief
     *
     * @return QString
     */
    QString getUsername();
    /**
     * @brief
     *
     * @return QString
     */
    QString getEmail() ;
    /**
     * @brief
     *
     * @return QString
     */
    QString getMobile() ;
    /**
     * @brief
     *
     * @return QPixmap
     */
    QPixmap getProfilepic();
    /**
     * @brief
     *
     * @return QString
     */
    QString getFriendslist();

private:

    QString id; /**< TODO: describe */
    QString username; /**< TODO: describe */
    QString email; /**< TODO: describe */
    QString mobile; /**< TODO: describe */
    QPixmap profilepic; /**< TODO: describe */
    QString friendslist; /**< TODO: describe */

};





#endif // USER_H
