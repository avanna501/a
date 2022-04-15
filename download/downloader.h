#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkReply>


//class QtDownload : public QObject
//{
//    Q_OBJECT
//public:
//    explicit QtDownload();
//    ~QtDownload();

//    void setTarget(const QString& t);

//private:
//    QNetworkAccessManager manager;
//    QString target;

////    void connectSignalsAndSlots();
////QNetworkReply* reply;
//signals:
//    void done();

//public slots:
//    void download();
//    void downloadFinished(QNetworkReply* data);
//    void downloadProgress(qint64 recieved, qint64 total);
//};

class Downloader : public QObject
{
    Q_OBJECT

public:
    explicit Downloader();
    ~Downloader();

    void setTarget(const QString& t);

private:
    QNetworkAccessManager manager;
    QString target;
    int i=1;
//    QNetworkReply* reply;
    QString file_name;

public slots:
    void download_request();
    void download();
    //void save();
};

#endif // DOWNLOADER_H
