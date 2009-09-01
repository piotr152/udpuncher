/**
 * @file
 * @author  mokasin <mok4sin@googlemail.com>
 * @version testing
 *
 * @section LICENSE
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details at
 * http://www.gnu.org/copyleft/gpl.html
 *
 * @section DESCRIPTION
 *
 *
 */

#ifndef UDPUNCHER_H
#define UDPUNCHER_H

#include <QtGui/QMainWindow>
#include "ui_udpuncher.h"
#include "Client.h"

class udpuncher : public QMainWindow
{
    Q_OBJECT

public:
    udpuncher(QWidget *parent = 0);
    ~udpuncher();

private:
    Ui::udpuncherClass ui;
    QStatusBar *Statusbar;
    Client *UdpClient;
    QTimer *Timer;

private slots:
    void on_pushButton_Connect_clicked();
    void on_lineEdit_IP_editingFinished();
    void on_lineEdit_Port_editingFinished();

    void on_pushButton_ping_clicked(bool checked);
    void slot_Timer_timeout();
    void slot_Client_readDatagram(QByteArray datagram, QHostAddress sender);
};

#endif // UDPUNCHER_H
