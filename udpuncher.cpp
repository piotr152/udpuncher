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

udpuncher::udpuncher(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    Statusbar = statusBar();

    UdpClient = new Client(QHostAddress().setAddress(ui.lineEdit_IP->text()), ui.lineEdit_Port->text().toInt());

    connect(UdpClient, SIGNAL(readDatagram(QByteArray , QHostAddress)), this, SLOT(on_Client_readDatagram(QByteArray , QHostAddress)));

}

udpuncher::~udpuncher()
{
    delete UdpClient;
}

void udpuncher::on_pushButton_Connect_clicked(bool checked)
{
    if(ui.lineEdit_Port->text() == "") {
        Statusbar->showMessage(tr("ERORR: Please insert a port."), 4000);
        ui.lineEdit_Port->setFocus();
    } else {
        ui.textEdit_Output->append(tr("Connecting to %1...").arg(UdpClient->IP.toString()));
        ui.textEdit_Output->append(tr("Sending a message..."));
        UdpClient->sendMessage(tr("Hello World from %1").arg(QHostAddress::LocalHost));
    }
}

void udpuncher::on_lineEdit_IP_editingFinished()
{
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

void udpuncher::on_Client_readDatagram(QByteArray datagram, QHostAddress sender)
{
    ui.textEdit_Output->append(tr("Message received from %1 at %2: %3").arg(sender.toString()).arg(QTime().currentTime().toString()).arg(datagram.data()));
}
