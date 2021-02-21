#ifndef CHAT_H
#define CHAT_H

#include <QMainWindow>
#include<QDebug>
#include <string>

class chat
{
public:
    chat();

    void setOldchatlogid(int s);
    void setNewchatlogid(int s);
    void setuser1(QString s);
    void setuser2(QString s);
    void setdate(QString s);
    void setmessage(QStringList s);
    void addTOmessage(QString s);
    void setttopicname(QString s);

    int getOldchatlogid();
    int getNewchatlogid();
    QString getuser1();
    QString getuser2();
    QString getdate();
    QStringList getmessage();
    QString gettopicname();



private:

    int Oldchatlogid;
    int Newchatlogid;
    QString user1;
    QString user2;
    QString date;
    QStringList message;
    QString topicname;

};

#endif // CHAT_H
