#include "chat.h"

chat::chat()
{

}


void chat::setOldchatlogid(int s) {
      Oldchatlogid = s;
}
void chat::setNewchatlogid(int s) {
      Newchatlogid = s;
}
void chat::setuser1(QString s) {
    user1 = s;
}
void chat::setuser2(QString s){
      user2 = s;
}
void chat::setdate(QString s){
      date = s;
}
void chat::setmessage(QStringList s) {
      message = s;
}


void chat::addTOmessage(QString s) {
      this->message.append(s);
}

void chat::setttopicname(QString s) {
    topicname = s;
}


int chat::getOldchatlogid() {
      return Oldchatlogid;
 }
int chat::getNewchatlogid() {
      return Newchatlogid;
 }
    // Getter
QString chat::getuser1() {
      return user1;
 }
QString chat::getuser2() {
      return user2;
    }
QString chat::getdate() {
      return date;
    }
QStringList chat::getmessage() {
      return message;
    }
QString chat::gettopicname() {
      return topicname;
    }
