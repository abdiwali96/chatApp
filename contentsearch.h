#ifndef CONTENTSEARCH_H
#define CONTENTSEARCH_H

#include <QMainWindow>
#include "user.h"
#include "chat.h"
#include "databaseconnection.h"
namespace Ui {
class contentsearch;
}

/**
 * @brief
 *
 */
class contentsearch : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief
     *
     * @param User1
     * @param User2
     * @param parent
     */
    explicit contentsearch(User* User1,User* User2,QWidget *parent = nullptr);
    /**
     * @brief
     *
     */
    ~contentsearch();

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

    QString editdbmessage; /**< TODO: describe */

    QString Themessage; /**< TODO: describe */

private slots:
    /**
     * @brief
     *
     */
    void on_Searchbutton_clicked();

    /**
     * @brief
     *
     */
    void on_editselect_clicked();

    /**
     * @brief
     *
     */
    void on_listofmessages_itemClicked();

    /**
     * @brief
     *
     */
    void on_pushButton_4_clicked();

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
    void on_pushButton_clicked();

    /**
     * @brief
     *
     */
    void on_pushButton_2_clicked();

private:
    Ui::contentsearch *ui; /**< TODO: describe */

    User *User1; /**< TODO: describe */

    User *User2; /**< TODO: describe */

};

#endif // CONTENTSEARCH_H
