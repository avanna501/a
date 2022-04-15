#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QDialog>
#include <QAbstractSocket>
#include <QTcpSocket>
#include <QVector>
#include <QComboBox>
#include <QLineEdit>
#include <QDialog>
#include <QPushButton>

//QT_BEGIN_NAMESPACE
//namespace Ui { class MainWindow; }
//QT_END_NAMESPACE

//class MainWindow : public QMainWindow
//{
//    Q_OBJECT

//public:
//    MainWindow(QWidget *parent = nullptr);
//    ~MainWindow();

//private:
//    Ui::MainWindow *ui;
//};

class MyClient : public QDialog
{
    Q_OBJECT

public:
    MyClient(/*QWidget *parent = nullptr*/);
signals:
//    void DoneDownloading();

//private slots:
public slots:
//    void request();
//    void processing_the_file();
//    void displayError(QAbstractSocket::SocketError socketError);
//    void enableGetFortuneButton();
    void segmentation();
//    void loadImage();
    void download();
private:
    int num;
//    QComboBox *hostCombo = nullptr;
//    QLineEdit *portLineEdit = nullptr;
//    QLabel *statusLabel = nullptr;
//    QPushButton *getTheFile;
//    QTcpSocket *tcpSocket = nullptr;
//    QDataStream in;
    QString line="https://aws-tiqets-cdn.imgix.net/images/content/0bda496746574de3ac1ec5c68616272b.jpg?auto=format&fit=crop&h=800&ixlib=python-3.2.1&q=70&w=800&s=6eafdc6974c5a807c1233ab21bfbd97bhttps://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.wanderingcrystal.com%2Fhaunted-castles-to-stay-in-scotland%2F&psig=AOvVaw0owyPUDKvXlzpJjgmiFe8z&ust=1649863100702000&source=images&cd=vfe&ved=0CAcQjRxqFwoTCIifxZfpjvcCFQAAAAAdAAAAABAU\n            https://imgs.search.brave.com/sPzDmtXCEi4leN34YmRUXRiYNLNdni21mtX9xr_qY1Y/rs:fit:1200:1200:1/g:ce/aHR0cHM6Ly93d3cu/dmlzaXRzY290bGFu/ZC5jb20vYmxvZy93/cC1jb250ZW50L3Vw/bG9hZHMvMjAxOS8w/OC92aXNpdHNjb3Rs/YW5kXzI2MDU3NzQ4/NzUyLmpwZw\n            https://i0.wp.com/tiqets-cdn.s3.eu-west-1.amazonaws.com/wordpress/blog/wp-content/uploads/2020/12/08154928/sagrada.jpg?fit=1288%2C1288&ssl=1";
    QList<QString> list;
};
#endif // CLIENT_H
