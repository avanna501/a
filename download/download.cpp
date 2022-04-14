#include "downloader.h"

#include <QUrl>
#include <QNetworkRequest>
#include <QFile>
#include <QDebug>
#include <QCoreApplication>
#include <QPixmap>
#include <QString>

//QtDownload::QtDownload() : QObject(0)
//{

//    QObject::connect(&manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(downloadFinished(QNetworkReply*)));
//}


//QtDownload::~QtDownload(){}

////void QtDownload::connectSignalsAndSlots()
////{
////    QObject::connect(&manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(downloadFinished(QNetworkReply*)));
////   QObject::connect(reply, SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(downloadProgress(qint64,qint64)));
////}

//void QtDownload::setTarget(const QString &t)
//{
//    this->target = t;
//}

//void QtDownload::downloadFinished(QNetworkReply *data)
//{
//    QFile localFile("C:/Users/inter/projects_a/client_server/server_client/download/downloadedfile.png");
//    if (!localFile.open(QIODevice::WriteOnly))
//        return;
//    const QByteArray sdata = data->readAll();
//    localFile.write(sdata);
//    qDebug() << sdata;
//    localFile.close();




////    QByteArray jpegData = pic.toLocal8Bit();
////    QPixmap pixmap;
////    pixmap.loadFromData(jpegData);
//////    QPixmap scaled = pixmap.scaled(128,64,Qt::IgnoreAspectRatio, Qt::FastTransformation);
////    l.setPixmap(scaled);
////    l.show();
////    QString filename = QFileDialog::getSaveFileName(this, tr("Save Skin"), "/home/ihorse1/10-03-2015", ,tr("JPEG Image(*.jpg)"));
////    QFile file (filename);
////    file.open(QIODevice::WriteOnly);
////    QDataStream out (&file);
////    out << reply;
////    qDebug()<<out;
////    file.close();






//    emit done();
//}

//void QtDownload::download()
//{
//    QUrl url = QUrl::fromEncoded(this->target.toLocal8Bit());
//    QNetworkRequest request(url);
//    QObject::connect(manager.get(request), SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(downloadProgress(qint64,qint64)));
//}

//void QtDownload::downloadProgress(qint64 recieved, qint64 total)
//{
//    qDebug() << recieved << total;
//}


Downloader::Downloader() : QObject(0)
{
//    QObject::connect(&manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(downloadFinished(QNetworkReply*)));
}
Downloader::~Downloader(){}

void Downloader::setTarget(const QString &t)
{
    this->target = t;
}

void Downloader::download_request()
{
    QUrl url = target;
    QNetworkRequest request(url);
    QNetworkReply* reply = manager.get(request);

    QObject::connect(reply,&QNetworkReply::finished,this,download(reply));
}

bool Downloader::download(QNetworkReply * reply)
{
    QString file_name=QStringLiteral("C:/Users/inter/projects_a/client_server/server_client/download/downloadedfile_%1.png").arg(i);
    QFile localFile(file_name);
    if (!localFile.open(QIODevice::WriteOnly))
        return false;
    QByteArray sdata = reply->readAll();
    localFile.write(sdata);
    qDebug() << sdata;
    localFile.close();
    return true;
}
