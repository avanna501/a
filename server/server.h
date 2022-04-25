#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QString>
#include <QList>
#include <QFile>
#include <QRandomGenerator>
#include <QTcpServer>
#include <QTcpSocket>

class MyServer : public QTcpServer
{
    Q_OBJECT

public:
    MyServer();
    void read();
    QString file_name="C:/Users/inter/projects_a/server_client_string/a/text.txt";

public slots:
    void incoming_connection();
private:
    QTcpSocket * soc;
    QVector<QTcpSocket*> s;
//    QList<QString> list={};
    QString list;
};
//qintptr socketDescriptor
#endif // SERVER_H
