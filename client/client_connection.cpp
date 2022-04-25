#include "client_connection.h"

#include <QWidget>
#include <QTcpSocket>
#include <QTcpServer>
#include <QComboBox>
#include <QLineEdit>
#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QDebug>
#include <QHostInfo>
#include <QNetworkInterface>
#include <QDialogButtonBox>
#include <QGuiApplication>
#include <QGroupBox>
#include <QTimer>
#include <QMessageBox>
#include <QStyleHints>
#include <QHostAddress>

MyClient::MyClient(){qInfo()<<"I'm in the constructor of MyClass";}

void MyClient::request(QString server_ip)
{
    qInfo()<<"I'm in MyClient.request";
    QHostAddress ip;
    ip.setAddress(server_ip);
    qInfo()<<ip;
//    QTcpSocket * tcp=new QTcpSocket(this);
    tcp/*Socket*/->connectToHost(ip,2525);
    qInfo()<<"HERE";
    in.setDevice(tcp);
    in.setVersion(QDataStream::Qt_4_0);
    connect(tcp/*Socket*/, &QTcpSocket::readyRead,this,&MyClient::read);
}

void MyClient::read()
{
    qInfo()<<"function read";

    in.startTransaction();
    in >> line;
    qInfo()<<line;
    if (!in.commitTransaction())
        return;
    tcp->deleteLater();

}
