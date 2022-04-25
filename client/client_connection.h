#ifndef CLIENT_CONNECTION_H
#define CLIENT_CONNECTION_H

#include <QTcpSocket>
#include <QHostInfo>
#include <QDataStream>
#include <QString>


class MyClient : public QObject
{
    Q_OBJECT


public:
//    explicit MyClient(QWidget *parent = nullptr);
    MyClient();

    QString line;
    void request(QString server_ip);

//private slots:
    void read();
//    void displayError(QAbstractSocket::SocketError socketError);

//private:
    QHostInfo hostIP;

    QTcpSocket *tcpSocket = nullptr;
    QDataStream in;

};

#endif // CLIENT_CONNECTION_H
