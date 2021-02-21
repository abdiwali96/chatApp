#ifndef UPLOADPIC_H
#define UPLOADPIC_H

#include <QMainWindow>
#include <QFileDialog>


namespace Ui {
class uploadpic;
}

class uploadpic : public QMainWindow
{
    Q_OBJECT

public:
    explicit uploadpic(QString text,QWidget *parent = nullptr);
    ~uploadpic();

     QByteArray byte;


private slots:
    void on_ReturnHomeBtn_clicked();

    void on_ChooseImage_clicked();



    void on_Update_clicked();

private:
    Ui::uploadpic *ui;

    QString LogginUser2profilepic;




};

#endif // UPLOADPIC_H
