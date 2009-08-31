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


#include "Client.h"

/**
 * Constructor that sets IP and port.
 * @param IP IP of receiver
 * @param Port own and receivers port
 */
Client::Client(QHostAddress IP, quint16 Port)
{
    this->IP = IP;
    this->Port = Port;

    //bind socket and make sure the port can be changed
    UdpSocket.bind(Port, QUdpSocket::ShareAddress
                       | QUdpSocket::ReuseAddressHint);
    //wants to listen
    connect(&UdpSocket, SIGNAL(readyRead()),
            this, SLOT(readPendingDatagrams()));
}

/**
 * Setter for Port. Changes also listen port of the server.
 * @param Port Server listens now to that port
 */
void Client::setPort(quint16 Port)
{
    UdpSocket.disconnectFromHost();
    UdpSocket.bind(Port, QUdpSocket::ShareAddress
                       | QUdpSocket::ReuseAddressHint);
    this->Port = Port;
}

/**
 * Slot for received datagram management
 */
void Client::readPendingDatagrams()
{
    //iterize through message queue
    while(UdpSocket.hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(UdpSocket.pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;

        UdpSocket.readDatagram(datagram.data(), datagram.size(),
                                &sender, &senderPort);
        //inform caller
        emit readDatagram(datagram, sender);
    }
}

/**
 * Sends a message to Client::IP on port Client::Port.
 * @param Message A string to send.
 */
void Client::sendMessage(QString Message)
{
    //have to change encoding
    UdpSocket.writeDatagram(Message.toLocal8Bit(), IP, Port);
}
