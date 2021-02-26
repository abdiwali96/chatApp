#ifndef HISTORYAPPWINDOW_H
#define HISTORYAPPWINDOW_H

#include <QMainWindow>
#include "user.h"
#include "chat.h"
#include "databaseconnection.h"
namespace Ui {
class historyappwindow;
}

/**
 * @brief
 *
 */
class historyappwindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief
     *
     * @param User1
     * @param User2
     * @param Topic
     * @param parent
     */
    explicit historyappwindow(User* User1,User* User2,QString Topic,QWidget *parent = nullptr);
    /**
     * @brief
     *
     */
    ~historyappwindow();

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
    void SetObject(QString s);

    /**
     * @brief
     *
     * @return User
     */
    User* GetObject2();

    /**
     * @brief
     *
     * @param s
     */
    void SetObject2(QString s);

    /**
     * @brief
     *
     */
    void GetMessageHistory();

    /**
     * @brief
     *
     */
    void searchRescord();

    /**
     * @brief
     *
     */
    void Query();




    QString dbmessage; /**< TODO: describe */
    QString m; /**< TODO: describe */

private slots:
    /**
     * @brief
     *
     */
    void on_OpenAttachment_clicked();

    /**
     * @brief
     *
     */
    void on_pushButton_2_clicked();

    /**
     * @brief
     *
     */
    void on_pushButton_clicked();

    /**
     * @brief
     *
     */
    void on_Searchbutton_clicked();

    /**
     * @brief
     *
     */
    void on_deletemessagebtn_clicked();

    /**
     * @brief
     *
     */
    void on_pushButton_3_clicked();

    /**
     * @brief
     *
     */
    void on_pushButton_4_clicked();

private:
    Ui::historyappwindow *ui; /**< TODO: describe */

    User *User1; /**< TODO: describe */

    User *User2; /**< TODO: describe */

    QString Topic; /**< TODO: describe */

    chat *chatobject; /**< TODO: describe */


};

#endif // HISTORYAPPWINDOW_H
