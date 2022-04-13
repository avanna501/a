#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QDialog>
#include <QAbstractSocket>
#include <QTcpSocket>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

class MyClient : public QDialog
{
    Q_OBJECT

    MyClient(/*QWidget *parent = nullptr*/);

private slots:
    void request();
    void processing_the_file();
    void displayError(QAbstractSocket::SocketError socketError);
//    void enableGetFortuneButton();
    void segmentation();

private:
//    QComboBox *hostCombo = nullptr;
//    QLineEdit *portLineEdit = nullptr;
//    QLabel *statusLabel = nullptr;
    QPushButton *getTheFile;
    QTcpSocket *tcpSocket = nullptr;
    QDataStream in;
    QString line;
    QVector<QString> list;
};
#endif // CLIENT_H
