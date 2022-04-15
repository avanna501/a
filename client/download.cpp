#include "download.h"
#include <QUrl>
#include <QNetworkRequest>
#include <QFile>
#include <QDebug>
#include <QCoreApplication>
#include <QPixmap>
#include <QString>

Downloader::Downloader() : QObject(0)
{}
Downloader::~Downloader(){}

void Downloader::setTarget(const QString &t,int j)
{
    this->target = t;
    download_request(j);
}

void Downloader::download_request(int j)
{
    QUrl url = target;
    i=j;
    QNetworkRequest request(url);
    QNetworkReply* reply = manager.get(request);

    QObject::connect(reply,&QNetworkReply::finished,this,&Downloader::download);
}

void Downloader::download()
{
    auto rep = dynamic_cast<QNetworkReply*>(sender());
    if(!rep)
    {
        return;
    }
    file_name=QStringLiteral("C:/Users/inter/projects_a/client_server/server_client/download/downloadedfile_%1.png").arg(i);
    QFile localFile(file_name);
    if (!localFile.open(QIODevice::WriteOnly))
        return ;
    auto data = rep->readAll();
    localFile.write(data);
    localFile.close();
    rep->deleteLater();
    emit done();
}
