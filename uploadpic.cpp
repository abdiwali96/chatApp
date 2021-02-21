#include "uploadpic.h"
#include "ui_uploadpic.h"

#include "homepage.h"
#include "login.h"
#include "databaseconnection.h"

/*
#include<QDebug>
#include <string>
#include <QPixmap>
#include <QByteArray>
#include <QSqlDatabase>
#include <QSqlError>
*/

uploadpic::uploadpic(QString text, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::uploadpic)
{
    this->setFixedSize(800,600);
    LogginUser2profilepic = text;
    ui->setupUi(this);

    ui->label->setText(LogginUser2profilepic);

}

uploadpic::~uploadpic()
{
    delete ui;
}

void uploadpic::on_ReturnHomeBtn_clicked()
{
    // this->hide();
    homepage *picbacktohomepage;
    this->close();
    picbacktohomepage = new homepage(LogginUser2profilepic, this);
    picbacktohomepage->show();


}

void uploadpic::on_ChooseImage_clicked()
{
    QByteArray byte;
    QString filename = QFileDialog::getOpenFileName(this,tr("Choose"), "", tr("Images (*.png *.jpg *.jpeg *.bmp *.gif)"));

        if(QString::compare(filename, QString()) != 0){
            QImage image;
            bool valid = image.load(filename);

            if (valid){

                image = image.scaledToWidth(ui->imageupload->width(), Qt:: SmoothTransformation);
                 QMessageBox::information(this,"Success","Image found");
                ui->imageupload->setPixmap(QPixmap::fromImage(image));


                QFile file(filename);
                byte = file.readAll();
                if(file.open(QIODevice::ReadOnly))
                    {
                        byte = file.readAll();
                        file.close();

                    }


            }
            else {
                //ERROR handling Stuff
            }
        }
        this->byte = byte;
}




void uploadpic::on_Update_clicked()
{
    if (this->byte.isEmpty()){
        QMessageBox::information(this,"try again","YOU HAVE NOT UPLOADED AN NEW IMAGE");
    }else {
        QMessageBox::information(this,"success","YOU HAVE UPLOADED AN NEW IMAGE");
        QSqlQuery query(QSqlDatabase::database("QMYSQL"));
        query.prepare("UPDATE members SET ProfilePic = :image WHERE username = :username");
        query.bindValue(":username",LogginUser2profilepic);
        query.bindValue(":image", this->byte , QSql::In | QSql::Binary);

        query.exec();
    }

}
