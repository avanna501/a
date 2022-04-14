#include "downloader.h"
#include <QTimer>
#include <QApplication>

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
    Downloader dl;

    dl.setTarget("https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.wanderingcrystal.com%2Fhaunted-castles-to-stay-in-scotland%2F&psig=AOvVaw0owyPUDKvXlzpJjgmiFe8z&ust=1649863100702000&source=images&cd=vfe&ved=0CAcQjRxqFwoTCIifxZfpjvcCFQAAAAAdAAAAABAU");

    dl.download_request();
    //quit when the download is done.
    QObject::connect(&dl, SIGNAL(done()), &app, SLOT(quit()));
    return app.exec();
}
