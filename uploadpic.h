#ifndef UPLOADPIC_H
#define UPLOADPIC_H

#include <QMainWindow>
#include <QFileDialog>
#include "user.h"


namespace Ui {
class uploadpic;
}

/**
 * @brief
 *
 */
class uploadpic : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief
     *
     * @param User1
     * @param parent
     */
    explicit uploadpic(User* User1,QWidget *parent = nullptr);
    /**
     * @brief
     *
     */
    ~uploadpic();
     QByteArray byte; /**< TODO: describe */


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
     void setProfilepic(QPixmap s) ;



private slots:
    /**
     * @brief
     *
     */
    void on_ReturnHomeBtn_clicked();

    /**
     * @brief
     *
     */
    void on_ChooseImage_clicked();



    /**
     * @brief
     *
     */
    void on_Update_clicked();

private:
    Ui::uploadpic *ui; /**< TODO: describe */

    User *User1; /**< TODO: describe */

    QString LogginUser2profilepic; /**< TODO: describe */




};

#endif // UPLOADPIC_H
