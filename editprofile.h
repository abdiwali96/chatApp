#ifndef EDITPROFILE_H
#define EDITPROFILE_H

#include <QMainWindow>
#include <QFileDialog>

namespace Ui {
class Editprofile;
}

class Editprofile : public QMainWindow
{
    Q_OBJECT

public:
    explicit Editprofile(QString text,QWidget *parent = nullptr);
    ~Editprofile();
    QString newusername;


private slots:
    void on_pushButton_clicked();

    void on_UpdatebuttonUsername_clicked();

    void on_ReturnHome_clicked();

private:
    Ui::Editprofile *ui;

    QString LogginUser2editDets;

};

#endif // EDITPROFILE_H
