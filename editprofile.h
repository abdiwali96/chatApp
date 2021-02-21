#ifndef EDITPROFILE_H
#define EDITPROFILE_H

#include <QMainWindow>
#include <QFileDialog>
#include "user.h"
namespace Ui {
class Editprofile;
}

class Editprofile : public QMainWindow
{
    Q_OBJECT

public:
    explicit Editprofile(User* User1,QWidget *parent = nullptr);
    ~Editprofile();
    QString newusername;

    //User *User1;

    User* GetObject();

    void SetObject(QString s) ;


private slots:
    void on_pushButton_clicked();

    void on_UpdatebuttonUsername_clicked();

    void on_ReturnHome_clicked();



private:
    Ui::Editprofile *ui;

    User *User1;

   // QString LogginUser2editDets;

};

#endif // EDITPROFILE_H
