#include "server.h"
#include <QDebug>
#include <QDataStream>
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QNetworkInterface>
#include <QLabel>

MyServer::MyServer()
{
    read();
    if (!list.isEmpty() && listen(QHostAddress::Any, 2525))
    {
       qInfo() << "Server Started";
       QString ipAddress;
         QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
         for (int i = 0; i < ipAddressesList.size(); ++i) {
             if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
                 ipAddressesList.at(i).toIPv4Address()) {
                 ipAddress = ipAddressesList.at(i).toString();
                 break;
             }
         }
         qInfo()<<ipAddress;
       connect(this, &QTcpServer::newConnection, this, &MyServer::incoming_connection);
    }

    else
        qInfo() << "Error starting server or empty file";

}

void MyServer::read()
{

    QFile file(file_name);
    if (!file.exists())
    {
        qDebug()<<"file not found";
        return;
    }

    if (!file.open(QIODevice::OpenModeFlag::ReadOnly))
    {
        qDebug()<<"couldn't open the file";
        return;
    }
//    while(!file.atEnd())
//        list.append(file.readLine());
    list=file.readAll();
 }

void MyServer::incoming_connection()
{
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_10);

    out << list;

    soc = this->nextPendingConnection();
    connect(soc, &QAbstractSocket::disconnected, soc, &QObject::deleteLater);
    qInfo()<<"new connection";
    soc->write(data);
    soc->disconnectFromHost();
}
