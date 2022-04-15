#include "client.h"
#include "download.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyClient my;
    my.segmentation();
    return a.exec();
}
