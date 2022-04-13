#include "client.h"

//MainWindow::MainWindow(QWidget *parent)
//    : QMainWindow(parent)
//    , ui(new Ui::MainWindow)
//{
//    ui->setupUi(this);
//}

//MainWindow::~MainWindow()
//{
//    delete ui;
//}

MyClient::MyClient()
{

}

void MyClient::processing_the_file()
{
    in.startTransaction();

    QString line;
    in >> line;

    if (!in.commitTransaction())
        return;

    segmentation();
//    file
//            statusLabel->setText(currentFortune);
//    getFortuneButton->setEnabled(true);

}

void MyClient::segmentation()
{

}

