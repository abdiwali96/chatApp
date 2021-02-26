/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMqttClient>
#include "user.h"
#include <QMainWindow>
#include <QFileDialog>
#include <QListWidgetItem>
#include <QPdfWriter>
#include <QDate>
#include "chat.h"
namespace Ui {
class MainWindow;
}

/**
 * @brief
 *
 */
class MainWindow : public QMainWindow
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
    explicit MainWindow(User* User1,User* User2,QString Topic,  QWidget *parent = nullptr);
    /**
     * @brief
     *
     */
    ~MainWindow();

    /**
     * @brief
     *
     */
    void GetEmojis();

    /**
     * @brief
     *
     */
    void GetListUpdate();

    /**
     * @brief
     *
     */
    void GetMessageHistory();

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

    QString uploadfilename; /**< TODO: describe */
    QByteArray byte0; /**< TODO: describe */



public slots:
    /**
     * @brief
     *
     * @param p
     */
    void setClientPort(int p);

private slots:

    /**
     * @brief
     *
     */
    void on_buttonConnect_clicked();

    /**
     * @brief
     *
     */
    void on_buttonQuit_clicked();

    /**
     * @brief
     *
     */
    void updateLogStateChange();

    /**
     * @brief
     *
     */
    void brokerDisconnected();

    /**
     * @brief
     *
     */
    void on_buttonPublish_clicked();

    /**
     * @brief
     *
     */
    void on_buttonSubscribe_clicked();

    /**
     * @brief
     *
     */
    void on_Uploadfile_clicked();

    /**
     * @brief
     *
     */
    void on_OpenAttachment_clicked();

    /**
     * @brief
     *
     * @param item
     */
    void on_Emojiwidget_itemClicked(QListWidgetItem *item);

    /**
     * @brief
     *
     */
    void on_returnhome_clicked();

    /**
     * @brief
     *
     */
    void on_refreshattachments_clicked();

private:
    Ui::MainWindow *ui; /**< TODO: describe */

    QMqttClient *m_client; /**< TODO: describe */

    chat *chatobject; /**< TODO: describe */

    User *User1; /**< TODO: describe */

    User *User2; /**< TODO: describe */


};

#endif // MAINWINDOW_H
