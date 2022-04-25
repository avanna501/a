#include "widget.h"
#include "ui_widget.h"
#include "client_connection.h"
#include <QObject>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{/*ui->server_ip_line->text()*/
    ui->setupUi(this);
//    connect(ui->pushButton,&QPushButton::clicked,&client,&MyClient::request);     //  how to modify this line so that it works
//    MyClient client;
//  connect(ui->pushButton, &QPushButton::clicked, this, [&client,ui->server_ip_line]
//                                              {client.request(ui->server_ip_line->text());});
    connect(ui->pushButton, &QPushButton::clicked,[this]{starting_the_request();});

};
Widget::~Widget()
{
    delete ui;
}

void Widget::starting_the_request()
{
    qInfo()<<"I'm in function sender";
    QString l=ui->server_ip_line->text();
    client.request(l);
}
