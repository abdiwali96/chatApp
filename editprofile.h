#ifndef EDITPROFILE_H
#define EDITPROFILE_H

#include <QMainWindow>
#include <QFileDialog>
#include "user.h"
namespace Ui {
class Editprofile;
}

/**
 * @brief
 *
 */
class Editprofile : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief
     *
     * @param User1
     * @param parent
     */
    explicit Editprofile(User* User1,QWidget *parent = nullptr);
    /**
     * @brief
     *
     */
    ~Editprofile();
    //QString newusername;

    //User *User1;

    /**
     * @brief
     *
     * @return User
     */
    User* GetObject();

    /**
     * @brief
     *
     * @param s
     */
    void SetObject(QString s) ;


private slots:
    /**
     * @brief
     *
     */
    void on_pushButton_clicked();

    /**
     * @brief
     *
     */
    void on_UpdatebuttonUsername_clicked();

    /**
     * @brief
     *
     */
    void on_ReturnHome_clicked();



private:
    Ui::Editprofile *ui; /**< TODO: describe */

    User *User1; /**< TODO: describe */

   // QString LogginUser2editDets;

};

#endif // EDITPROFILE_H
