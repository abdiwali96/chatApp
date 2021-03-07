#ifndef UPLOADPIC_H
#define UPLOADPIC_H

#include <QMainWindow>
#include <QFileDialog>
#include "user.h"


namespace Ui {
class uploadpic;
}


class uploadpic : public QMainWindow
{
    Q_OBJECT

public:

    explicit uploadpic(User* User1,QWidget *parent = nullptr);

    ~uploadpic();
     QByteArray byte;

     User* GetObject();

     void setProfilepic(QPixmap s) ;

private slots:

    void on_ReturnHomeBtn_clicked();

    void on_ChooseImage_clicked();

    void on_Update_clicked();

private:
    Ui::uploadpic *ui;

    User *User1;

    QString LogginUser2profilepic;

};

#endif // UPLOADPIC_H
