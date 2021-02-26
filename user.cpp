#include "user.h"



User::User(QString idnum, QString usernamenum, QString emailnum , QString mobilenum , QPixmap profilepicnum, QString friendslistnum){

     id = idnum;
     username = usernamenum;
     email = emailnum ;
     mobile = mobilenum;
     profilepic = profilepicnum;
     friendslist = friendslistnum;

}


    void User::setId(QString s) {
          id = s;
    }
    void User::setUsername(QString s) {
          username = s;
    }
    void User::setEmail(QString s) {
          email = s;
    }
    void User::setMobile(QString s) {
          mobile = s;
    }
    void User::setProfilepic(QPixmap s) {
          profilepic = s;
    }
    void User::setFriendslist(QString s) {
        friendslist = s;
    }


    QString User::getId() {
          return id;
     }
        // Getter
    QString User::getUsername() {
          return username;
     }
    QString User::getEmail() {
          return email;
        }
    QString User::getMobile() {
          return mobile;
        }
    QPixmap User::getProfilepic() {
          return profilepic;
        }
    QString User::getFriendslist() {
          return friendslist;
        }



