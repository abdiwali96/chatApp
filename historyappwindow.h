#ifndef HISTORYAPPWINDOW_H
#define HISTORYAPPWINDOW_H

#include <QMainWindow>
#include "user.h"
#include "chat.h"
#include "databaseconnection.h"
namespace Ui {
class historyappwindow;
}

class historyappwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit historyappwindow(User* User1,User* User2,QString Topic,QWidget *parent = nullptr);
    ~historyappwindow();

    User* GetObject();

    void SetObject(QString s);

    User* GetObject2();

    void SetObject2(QString s);

    void GetMessageHistory();

    void searchRescord();

    QString GetTopic();

    QString dbmessage;
    QString m;

private slots:
    void on_OpenAttachment_clicked();

private:
    Ui::historyappwindow *ui;

    User *User1;

    User *User2;

    QString Topic;

    chat *chatobject;


};

#endif // HISTORYAPPWINDOW_H
