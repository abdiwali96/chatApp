#ifndef CHAT_H
#define CHAT_H

#include <QMainWindow>
#include<QDebug>
#include <string>

/**
 * @brief
 *
 */
class chat
{
public:
    /**
     * @brief
     *
     */
    chat();

    /**
     * @brief
     *
     * @param s
     */
    void setOldchatlogid(int s);
    /**
     * @brief
     *
     * @param s
     */
    void setNewchatlogid(int s);
    /**
     * @brief
     *
     * @param s
     */
    void setuser1(QString s);
    /**
     * @brief
     *
     * @param s
     */
    void setuser2(QString s);
    /**
     * @brief
     *
     * @param s
     */
    void setdate(QString s);
    /**
     * @brief
     *
     * @param s
     */
    void setmessage(QStringList s);
    /**
     * @brief
     *
     * @param s
     */
    void addTOmessage(QString s);
    /**
     * @brief
     *
     * @param s
     */
    void setttopicname(QString s);

    /**
     * @brief
     *
     * @return int
     */
    int getOldchatlogid();
    /**
     * @brief
     *
     * @return int
     */
    int getNewchatlogid();
    /**
     * @brief
     *
     * @return QString
     */
    QString getuser1();
    /**
     * @brief
     *
     * @return QString
     */
    QString getuser2();
    /**
     * @brief
     *
     * @return QString
     */
    QString getdate();
    /**
     * @brief
     *
     * @return QStringList
     */
    QStringList getmessage();
    /**
     * @brief
     *
     * @return QString
     */
    QString gettopicname();



private:

    int Oldchatlogid; /**< TODO: describe */
    int Newchatlogid; /**< TODO: describe */
    QString user1; /**< TODO: describe */
    QString user2; /**< TODO: describe */
    QString date; /**< TODO: describe */
    QStringList message; /**< TODO: describe */
    QString topicname; /**< TODO: describe */

};

#endif // CHAT_H
