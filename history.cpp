#include "history.h"
#include "ui_history.h"
#include "login.h"

history::history(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::history)
{
    ui->setupUi(this);
   //this->User1 = User1 ;
   // this->User2 = User2 ;
   // this->Topic = Topic;


}

history::~history()
{
    delete ui;
}


