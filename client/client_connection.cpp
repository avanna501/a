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

MyClient::MyClient(){qInfo()<<"I'm in the constructor of MyClass";}


//MyClient::MyClient(QWidget *parent) : QObject(parent)
//    , host(new QLineEdit)
//    , portLineEdit(new QLineEdit)
//    , getPictures(new QPushButton(tr("Get URL-s")))
//    , tcpSocket(new QTcpSocket(this))


////    portLineEdit->setValidator(new QIntValidator(1, 65535, this));
//    hostIP.setHostName(host->text());
//    auto hostLabel = new QLabel(tr("&Server name:"));
//    hostLabel->setBuddy(host);



//    connect(getPictures, &QAbstractButton::clicked, this, &Client::requestURL);




void MyClient::request(QString server_ip)
{

    qInfo()<<"I'm in MyClient.request";
    qInfo()<<server_ip;

    hostIP.setHostName(server_ip);
    in.setDevice(tcpSocket);
    in.setVersion(QDataStream::Qt_4_0);
    qInfo()<<"I'm in MyClient.request 1";
//    tcpSocket->abort();

    connect (tcpSocket,&QTcpSocket::readyRead(),this,read);

    tcpSocket->connectToHost(server_ip,2525/*portLineEdit->text().toInt()*/);
    qInfo()<<"I'm in MyClient.request 2";
    connect(tcpSocket, &QIODevice::readyRead, this, &MyClient::read);
    qInfo()<<"I'm in MyClient.request 3";
//    connect(tcpSocket, &QAbstractSocket::errorOccurred, this, &MyClient::displayError);

}

void MyClient::read()
{
    in.startTransaction();
    in >> line;
    if (!in.commitTransaction())
        return;
}

////void MyClient::displayError(QAbstractSocket::SocketError socketError)
////{
////    switch (socketE[[rror)
////    {
////    case QAbstractSocket::RemoteHostClosedError: break;
////    case QAbstractSocket::HostNotFoundError:     QMessageBox::information(this, tr("Fortune Client"), tr("The host was not found. Please check the host name and port settings."));
////                                                     break;
////    case QAbstractSocket::ConnectionRefusedError:QMessageBox::information(this, tr("Fortune Client"), tr("The connection was refused by the peer. Make sure the fortune server is running, "
////                                                     "and check that the host name and port settings are correct."));
////                                                     break;
////    default:        QMessageBox::information(this, tr("Fortune Client"), tr("The following error occurred: %1.").arg(tcpSocket->errorString()));
////    }
////    getPictures->setEnabled(true);
////}
