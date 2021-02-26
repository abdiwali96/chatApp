#ifndef HOMEPAGE_H
#define HOMEPAGE_H


#include <QMainWindow>

#include "uploadpic.h"
#include "editprofile.h"
#include "mainwindow.h"
#include "historyappwindow.h"
#include "contentsearch.h"
namespace Ui {
class homepage;
}

/**
 * @brief
 *
 */
class homepage : public QMainWindow
{
    Q_OBJECT

public:
    //i added first part of parameter
    /**
     * @brief
     *
     * @param User1
     * @param parent
     */
    explicit homepage(User* User1,QWidget *parent = nullptr);
    /**
     * @brief
     *
     */
    ~homepage();

    /**
     * @brief
     *
     */
    void friendsetup();

    /**
     * @brief
     *
     */
    void createTopic();

    /**
     * @brief
     *
     */
    void ProfileSetup();

    /**
     * @brief
     *
     */
    void getNumerofMess();

    /**
     * @brief
     *
     */
    void getNumofMes24hrs();

    /**
     * @brief
     *
     */
    void getNumofAttach();

    /**
     * @brief
     *
     */
    void getFirstMessDate();


    /*
    QString User1_ID;
    QString User1_Username;
    QString User1_Email ;
    QString User1_Mobile ;
    QString User1_friendslistnum;
    */

    QString Topic;

    QString delimiter; /**< TODO: describe */

    QStringList fl ; /**< TODO: describe */
    QStringList friendID; /**< TODO: describe */
    QStringList friendUsernames; /**< TODO: describe */
    QVector<int> friendsIdList; /**< TODO: describe */
    QString friendusername; /**< TODO: describe */


private slots:

    /**
     * @brief
     *
     */
    void on_EditProfilePic_clicked();

    /**
     * @brief
     *
     */
    void on_EditProfilebutton_clicked();

    /**
     * @brief
     *
     */
    void on_Searchbutton_clicked();

    /**
     * @brief
     *
     */
    void on_Addfriend_clicked();

    /**
     * @brief
     *
     */
    void on_SendMessage_clicked();


    /**
     * @brief
     *
     */
    void on_listoffriends_itemClicked();

    /**
     * @brief
     *
     */
    void on_ViewHistory_clicked();

    /**
     * @brief
     *
     */
    void on_pushButton_clicked();

    /**
     * @brief
     *
     */
    void on_ViewAllHistory_clicked();

private:
    Ui::homepage *ui; /**< TODO: describe */

    User *User1; /**< TODO: describe */
    User *User2; /**< TODO: describe */


    //I added below
     QString LogginUser; /**< TODO: describe */
     //
     historyappwindow *historyapp; /**< TODO: describe */
     contentsearch *contentsearchwindow; /**< TODO: describe */
     Editprofile *editprofilecwindow; /**< TODO: describe */
     uploadpic *uploadpicwindow; /**< TODO: describe */
     MainWindow *mainwindowchat; /**< TODO: describe */


};

#endif // HOMEPAGE_H
