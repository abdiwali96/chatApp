#ifndef HISTORY_H
#define HISTORY_H

#include <QWidget>
#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QMainWindow>
#include "user.h"
#include "databaseconnection.h"


namespace Ui {
class history;
}

class history : public QWidget
{
    Q_OBJECT

public:
    explicit history(QWidget *parent = nullptr);
    ~history();

   // User *User1;

    //QString Topic;
   // User *User2;


   // User* GetObject();

   // QString GetTopic();

    //void SetObject(QString s) ;

    // MessageHistory();
//


private:
    Ui::history *ui;

  //  User *User1;

   // User *User2;

 //   QString Topic;


};

#endif // HISTORY_H
