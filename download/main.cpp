#include <QCoreApplication>
#include <QString>
#include <QList>
#include "d.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString line="https://aws-tiqets-cdn.imgix.net/images/content/0bda496746574de3ac1ec5c68616272b.jpg?auto=format&fit=crop&h=800&ixlib=python-3.2.1&q=70&w=800&s=6eafdc6974c5a807c1233ab21bfbd97bhttps://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.wanderingcrystal.com%2Fhaunted-castles-to-stay-in-scotland%2F&psig=AOvVaw0owyPUDKvXlzpJjgmiFe8z&ust=1649863100702000&source=images&cd=vfe&ved=0CAcQjRxqFwoTCIifxZfpjvcCFQAAAAAdAAAAABAU\nhttps://imgs.search.brave.com/sPzDmtXCEi4leN34YmRUXRiYNLNdni21mtX9xr_qY1Y/rs:fit:1200:1200:1/g:ce/aHR0cHM6Ly93d3cu/dmlzaXRzY290bGFu/ZC5jb20vYmxvZy93/cC1jb250ZW50L3Vw/bG9hZHMvMjAxOS8w/OC92aXNpdHNjb3Rs/YW5kXzI2MDU3NzQ4/NzUyLmpwZw\nhttps://i0.wp.com/tiqets-cdn.s3.eu-west-1.amazonaws.com/wordpress/blog/wp-content/uploads/2020/12/08154928/sagrada.jpg?fit=1288%2C1288&ssl=1";
//    QString line="line 1\nline 2\nline 3";
    QList<QString> list;

//    MyClient my;
    int i;
    for(i=0;line.indexOf("\n")>=0;i++)
    {
        list.append(line.mid(0, line.toStdString().find("\n")));
        line=line.mid(line.toStdString().find("\n")+1);
//        qInfo()<<list;
    }
    list.append(line);
    qInfo()<<"I've done 'segmentation' & here is the result:";
    i=0;

    QVector<Downloader> qd(list.size());

    for(;!list.isEmpty();)
    {
//        Downloader qd; // = new Downloader;
        qd[i].setTarget(list.takeAt(0));
        qd[i].download_request(i);
        i++;
    }
//        connect(&n[i-1],SIGNAL(Downloader::done()),this,{continue});


//    for(i=0;i<list.size();i++)
//    {
//        Downloader pic;
//        pic.setTarget(list[i],i);
//            qInfo()<<"I'm in 'download'"<<i;;
////        wait(pic.done())
//    }

    return a.exec();
}
