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


#include "udpuncher.h"
#include <qscrollbar.h>

udpuncher::udpuncher(QWidget *parent)
    : QMainWindow(parent)
{
    QHostAddress Address;

    ui.setupUi(this);
    Statusbar = statusBar();

    // initializing the connection manager Client with the IP and address from
    // the ui, listens to the same port
    Address.setAddress(ui.lineEdit_IP->text());
    UdpClient = new Client(Address, ui.lineEdit_Port->text().toInt());

    Timer = new QTimer(this);

    connect(Timer, SIGNAL(timeout()), this, SLOT(slot_Timer_timeout()));

    // to get informed when data arrives
    connect(UdpClient, SIGNAL(readDatagram(QByteArray , QHostAddress)),
            this, SLOT(slot_Client_readDatagram(QByteArray , QHostAddress)));
    //push button when enter pressed in message box
    connect(ui.lineEdit_Message, SIGNAL(returnPressed()),
            this, SLOT(on_pushButton_Connect_clicked()));

}

udpuncher::~udpuncher()
{
    delete UdpClient;
}

void udpuncher::on_pushButton_Connect_clicked()
{
    // make sure the port is correct
    if(ui.lineEdit_Port->text() == "") {
        Statusbar->showMessage(tr("ERORR: Please insert a port."), 4000);
        ui.lineEdit_Port->setFocus();
    } else {
        //TODO: It should send more in constant intervalls
        //ui.textEdit_Output->append(tr("Connecting to %1...")
        //                           .arg(UdpClient->IP.toString()));
        ui.textEdit_Output->append(tr("Sending a message: %1")
                                   .arg(ui.lineEdit_Message->text()));
        //send and clear
        UdpClient->sendMessage(ui.lineEdit_Message->text());
        ui.lineEdit_Message->clear();
    }
}

void udpuncher::on_lineEdit_IP_editingFinished()
{
    // check IP and jump to error, else set IP of UdpClient
    if(!UdpClient->IP.setAddress(ui.lineEdit_IP->text())) {
        int i;

        Statusbar->showMessage(tr("ERROR: IP address is not valid."));
        ui.lineEdit_IP->setFocus();
        for(i = 0; i<4; i++) {
            if(ui.lineEdit_IP->text().section('.', i, i).toInt() > 255) {
                break;
            }
        }
        ui.lineEdit_IP->setCursorPosition(i*4);
    } else {
        Statusbar->showMessage(tr("Valid IP inserted."), 4000);
    }
}

void udpuncher::on_lineEdit_Port_editingFinished()
{
    UdpClient->setPort(ui.lineEdit_Port->text().toInt());
}


void udpuncher::on_pushButton_ping_clicked(bool checked)
{
    if(checked) {
        Timer->start(2000);
        ui.pushButton_ping->setText(tr("S&top pinging"));
    } else {
        Timer->stop();
        ui.pushButton_ping->setText(tr("Start &pinging"));
    }
}

void udpuncher::slot_Timer_timeout()
{
    UdpClient->sendMessage(QString("PING:%1").
                            arg(QTime().currentTime().toString()));
    ui.textEdit_Output->append(tr("Sending ping signal: Ping!"));
}

/**
 * Slot for data arrival.
 * @param datagram contains the received raw data
 * @param sender sender's IP
 */
void udpuncher::slot_Client_readDatagram(QByteArray datagram,
                                         QHostAddress sender)
{
    ui.textEdit_Output->append(tr("Message received from %1 at %2: %3")
                               .arg(sender.toString())
                               .arg(QTime().currentTime().toString())
                               .arg(datagram.data()));
}

void udpuncher::on_textEdit_Output_textChanged()
{
    ui.textEdit_Output->verticalScrollBar()->setValue(
                ui.textEdit_Output->verticalScrollBar()->maximum());
}
