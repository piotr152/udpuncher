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
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details at
 * http://www.gnu.org/copyleft/gpl.html
 *
 * @section DESCRIPTION
 *
 *
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include <QObject>
#include <QtNetwork>

class Client : public QObject {
    Q_OBJECT
public:
    QHostAddress IP;
    quint16 Port;

    Client(QHostAddress IP, quint16 Port);

    QHostAddress getIP() const { return IP; }
    quint16 getPort() const { return Port; }

    void setIP(QHostAddress IP) { this->IP = IP; }
    void setPort(quint16 Port);

    void sendMessage(QString Message);

signals:
    void readDatagram(QByteArray datagram, QHostAddress sender);

private:
    QUdpSocket UdpSocket;
private slots:
    void readPendingDatagrams();
};

#endif /* CLIENT_H_ */
