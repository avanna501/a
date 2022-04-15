#include "client.h"
#include "download.h"
#include <QWidget>
#include <QTcpSocket>
#include <QTcpServer>
#include <QComboBox>
#include <QLineEdit>
#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QDebug>

void MyClient::segmentation()
{
    int i;
    for(i=0;line.indexOf("\n")>=0;i++)
    {
        list.append(line.mid(0, line.toStdString().find("\n")));
        line=line.mid(line.toStdString().find("\n")+1);
    }
    list.append(line);
    qInfo()<<"I'm in 'segmentation'";
}

void MyClient::download()
{
    int i;
    for(i=0;i<list.size();i++)
    {
        Downloader pic;
        pic.setTarget(list[i],i);
            qInfo()<<"I'm in 'download'"<<i;;
//        wait(pic.done())
    }
}



////MyClient::MyClient(/*QWidget *parent*/)
////    : QDialog(parent)
////        , hostCombo(new QComboBox)
////        , portLineEdit(new QLineEdit)
////        , getFortuneButton(new QPushButton(tr("Get Fortune")))
////        , tcpSocket(new QTcpSocket(this))
////{
////    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
//////! [0]
////    hostCombo->setEditable(true);
////    // find out name of this machine
////    QString name = QHostInfo::localHostName();
////    if (!name.isEmpty()) {
////        hostCombo->addItem(name);
////        QString domain = QHostInfo::localDomainName();
////        if (!domain.isEmpty())
////            hostCombo->addItem(name + QChar('.') + domain);
////    }
////    if (name != QLatin1String("localhost"))
////        hostCombo->addItem(QString("localhost"));
////    // find out IP addresses of this machine
////    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
////    // add non-localhost addresses
////    for (int i = 0; i < ipAddressesList.size(); ++i) {
////        if (!ipAddressesList.at(i).isLoopback())
////            hostCombo->addItem(ipAddressesList.at(i).toString());
////    }
////    // add localhost addresses
////    for (int i = 0; i < ipAddressesList.size(); ++i) {
////        if (ipAddressesList.at(i).isLoopback())
////            hostCombo->addItem(ipAddressesList.at(i).toString());
////    }

////    portLineEdit->setValidator(new QIntValidator(1, 65535, this));

////    auto hostLabel = new QLabel(tr("&Server name:"));
////    hostLabel->setBuddy(hostCombo);
////    auto portLabel = new QLabel(tr("S&erver port:"));
////    portLabel->setBuddy(portLineEdit);

////    statusLabel = new QLabel(tr("This examples requires that you run the "
////                                "Fortune Server example as well."));

////    getFortuneButton->setDefault(true);
////    getFortuneButton->setEnabled(false);

////    auto quitButton = new QPushButton(tr("Quit"));

////    auto buttonBox = new QDialogButtonBox;
////    buttonBox->addButton(getFortuneButton, QDialogButtonBox::ActionRole);
////    buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);

//////! [1]
////    in.setDevice(tcpSocket);
////    in.setVersion(QDataStream::Qt_4_0);
//////! [1]

////    connect(hostCombo, &QComboBox::editTextChanged,
////            this, &Client::enableGetFortuneButton);
////    connect(portLineEdit, &QLineEdit::textChanged,
////            this, &Client::enableGetFortuneButton);
////    connect(getFortuneButton, &QAbstractButton::clicked,
////            this, &Client::requestNewFortune);
////    connect(quitButton, &QAbstractButton::clicked, this, &QWidget::close);
//////! [2] //! [3]
////    connect(tcpSocket, &QIODevice::readyRead, this, &Client::readFortune);
//////! [2] //! [4]
////    connect(tcpSocket, &QAbstractSocket::errorOccurred,
//////! [3]
////            this, &Client::displayError);
//////! [4]

////    QGridLayout *mainLayout = nullptr;
////    if (QGuiApplication::styleHints()->showIsFullScreen() || QGuiApplication::styleHints()->showIsMaximized()) {
////        auto outerVerticalLayout = new QVBoxLayout(this);
////        outerVerticalLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Ignored, QSizePolicy::MinimumExpanding));
////        auto outerHorizontalLayout = new QHBoxLayout;
////        outerHorizontalLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::MinimumExpanding, QSizePolicy::Ignored));
////        auto groupBox = new QGroupBox(QGuiApplication::applicationDisplayName());
////        mainLayout = new QGridLayout(groupBox);
////        outerHorizontalLayout->addWidget(groupBox);
////        outerHorizontalLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::MinimumExpanding, QSizePolicy::Ignored));
////        outerVerticalLayout->addLayout(outerHorizontalLayout);
////        outerVerticalLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Ignored, QSizePolicy::MinimumExpanding));
////    } else {
////        mainLayout = new QGridLayout(this);
////    }
////    mainLayout->addWidget(hostLabel, 0, 0);
////    mainLayout->addWidget(hostCombo, 0, 1);
////    mainLayout->addWidget(portLabel, 1, 0);
////    mainLayout->addWidget(portLineEdit, 1, 1);
////    mainLayout->addWidget(statusLabel, 2, 0, 1, 2);
////    mainLayout->addWidget(buttonBox, 3, 0, 1, 2);

////    setWindowTitle(QGuiApplication::applicationDisplayName());
////    portLineEdit->setFocus();
//////! [5]
////}
//////! [5]

//////! [6]
////void Client::requestNewFortune()
////{
////    getFortuneButton->setEnabled(false);
////    tcpSocket->abort();
//////! [7]
////    tcpSocket->connectToHost(hostCombo->currentText(),
////                             portLineEdit->text().toInt());
//////! [7]
////}
//////! [6]

//////! [8]
////void Client::readFortune()
////{
////    in.startTransaction();

////    QString nextFortune;
////    in >> nextFortune;

////    if (!in.commitTransaction())
////        return;

////    if (nextFortune == currentFortune) {
////        QTimer::singleShot(0, this, &Client::requestNewFortune);
////        return;
////    }

////    currentFortune = nextFortune;
////    statusLabel->setText(currentFortune);
////    getFortuneButton->setEnabled(true);
////}
//////! [8]

//////! [13]
////void Client::displayError(QAbstractSocket::SocketError socketError)
////{
////    switch (socketError) {
////    case QAbstractSocket::RemoteHostClosedError:
////        break;
////    case QAbstractSocket::HostNotFoundError:
////        QMessageBox::information(this, tr("Fortune Client"),
////                                 tr("The host was not found. Please check the "
////                                    "host name and port settings."));
////        break;
////    case QAbstractSocket::ConnectionRefusedError:
////        QMessageBox::information(this, tr("Fortune Client"),
////                                 tr("The connection was refused by the peer. "
////                                    "Make sure the fortune server is running, "
////                                    "and check that the host name and port "
////                                    "settings are correct."));
////        break;
////    default:
////        QMessageBox::information(this, tr("Fortune Client"),
////                                 tr("The following error occurred: %1.")
////                                 .arg(tcpSocket->errorString()));
////    }

////    getFortuneButton->setEnabled(true);
////}
//}

//MyClient::MyClient()
//{
//    QVBoxLayout *mainLayout = new QVBoxLayout(this);

////    QGroupBox *optionsGroupBox = new QGroupBox(tr("Options"), this);
////    delaySpinBox = new QSpinBox(optionsGroupBox);
////    delaySpinBox->setSuffix(tr(" s"));
////    delaySpinBox->setMaximum(60);
////    connect(delaySpinBox, &QSpinBox::valueChanged,
////            this, &Screenshot::updateCheckBox);

////    ComboBox = new QComboBox;
////    QStringList list=(QStringList()<<"1"<<"1/2"<<"1/4"<<"1/8");
////    ComboBox->addItems(list);

////    hideThisWindowCheckBox = new QCheckBox(tr("Hide This Window"), optionsGroupBox);

////    QGridLayout *optionsGroupBoxLayout = new QGridLayout(optionsGroupBox);
////    optionsGroupBoxLayout->addWidget(new QLabel(tr("Screenshot Delay:"), this), 0, 0);
////    optionsGroupBoxLayout->addWidget(delaySpinBox, 0, 1);
////    optionsGroupBoxLayout->addWidget(new QLabel(tr("Screeshot Size:"), this));
////    optionsGroupBoxLayout->addWidget(ComboBox);
////    optionsGroupBoxLayout->addWidget(hideThisWindowCheckBox);

////    mainLayout->addWidget(optionsGroupBox);

////    QHBoxLayout *buttonsLayout = new QHBoxLayout;
////    newScreenshotButton = new QPushButton(tr("New Screenshot"), this);
////    connect(newScreenshotButton, &QPushButton::clicked, this, &Screenshot::newScreenshot);
////    buttonsLayout->addWidget(newScreenshotButton);

//    QPushButton *getTheFile = new QPushButton(tr("getTheFile"), this);
//    connect(getTheFile, &QPushButton::clicked, MyClient, &MyClient::request());
//    buttonsLayout->addWidget(getTheFile);
//    QPushButton *quitScreenshotButton = new QPushButton(tr("Quit"), this);
//    quitScreenshotButton->setShortcut(Qt::CTRL | Qt::Key_Q);
//    connect(quitScreenshotButton, &QPushButton::clicked, this, &QWidget::close);
//    buttonsLayout->addWidget(quitScreenshotButton);

//    buttonsLayout->addStretch();
//    mainLayout->addLayout(buttonsLayout);

//    shootScreen();
//    delaySpinBox->setValue(5);

//    setWindowTitle(tr("Screenshot"));
//}

//void MyClient::processing_the_file()
//{
//    in.startTransaction();

//    QString line;
//    in >> line;

//    if (!in.commitTransaction())
//        return;

//    segmentation();
//}




////! [13]

//void Client::enableGetFortuneButton()
//{
//    getFortuneButton->setEnabled(!hostCombo->currentText().isEmpty() &&
//                                 !portLineEdit->text().isEmpty());

//}

