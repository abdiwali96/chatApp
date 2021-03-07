#ifndef CONTENTSEARCH_H
#define CONTENTSEARCH_H

#include <QMainWindow>
#include "user.h"
#include "chat.h"
#include "databaseconnection.h"
namespace Ui {
class contentsearch;
}


class contentsearch : public QMainWindow
{
    Q_OBJECT

public:

    explicit contentsearch(User* User1,User* User2,QWidget *parent = nullptr);

    ~contentsearch();

    User* GetObject();

    void SetObject(QString s);

    User* GetObject2();

    void SetObject2(QString s);

    QString editdbmessage;
    QString Themessage;

private slots:

    void on_Searchbutton_clicked();

    void on_editselect_clicked();

    void on_listofmessages_itemClicked();

    void on_pushButton_4_clicked();

    void on_deletemessagebtn_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::contentsearch *ui;

    User *User1;

    User *User2;

};

#endif // CONTENTSEARCH_H
