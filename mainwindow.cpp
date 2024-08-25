#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QPixmap>
#include <QImageReader>
#include <qpainter.h>
#include <qpainterpath.h>

MainWindow::MainWindow(QWidget *parent)
    : BaseWindow(parent),
    ui(new Ui::MainWindow),
    networkManager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);

    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setContentsMargins(10, 50, 10, 5);

    QWidget *selectorBlock = new QWidget(centralWidget);
    selectorBlock->setStyleSheet("background-color: rgba(0, 0, 0, 0.2); border-radius: 15px;");
    selectorBlock->setFixedSize(270, 480);

    QWidget *titleBlock = new QWidget(centralWidget);
    titleBlock->setStyleSheet("background-color: rgba(0, 0, 0, 0.2); border-radius: 15px;");
    titleBlock->setFixedSize(380, 94);

    QWidget *playerBlock = new QWidget(centralWidget);
    playerBlock->setStyleSheet("background-color: rgba(0, 0, 0, 0.2); border-radius: 15px;");
    playerBlock->setFixedSize(274, 94);

    QLabel *playerHeadLabel = new QLabel(playerBlock);
    playerHeadLabel->setFixedSize(60, 60);

    playerHeadLabel->move(10, (playerBlock->height() - playerHeadLabel->height()) / 2);

    QString playerName = "datav3nom";
    QString url = QString("https://altromon.ob1lab.ru/api/skins/textures/head/%1").arg(playerName);
    QNetworkRequest request((QUrl(url)));
    QNetworkReply *reply = networkManager->get(request);

    connect(reply,
            &QNetworkReply::finished,
            this,
            [reply,
             playerHeadLabel]() {

        if (reply->error() == QNetworkReply::NoError) {
            QImageReader reader(reply);
            reader.setAutoTransform(true);
            QImage image = reader.read();

            if (!image.isNull()) {
                QPixmap pixmap = QPixmap::fromImage(image.scaled(60, 60, Qt::KeepAspectRatio, Qt::FastTransformation));
                QPixmap roundedPixmap(60, 60);
                roundedPixmap.fill(Qt::transparent);

                QPainter painter(&roundedPixmap);
                painter.setRenderHint(QPainter::Antialiasing);
                QPainterPath path;
                path.addRoundedRect(0, 0, 60, 60, 5, 5);
                painter.setClipPath(path);
                painter.drawPixmap(0, 0, pixmap);

                playerHeadLabel->setPixmap(roundedPixmap);
            }
        }
        reply->deleteLater();
    });


    QWidget *infoBlock = new QWidget(centralWidget);
    infoBlock->setStyleSheet("background-color: rgba(0, 0, 0, 0.2); border-radius: 15px;");
    infoBlock->setFixedSize(662, 129);

    QWidget *descriptionBlock = new QWidget(centralWidget);
    descriptionBlock->setStyleSheet("background-color: rgba(0, 0, 0, 0.2); border-radius: 15px;");
    descriptionBlock->setFixedSize(662, 163);

    QWidget *launchBlock = new QWidget(centralWidget);
    launchBlock->setStyleSheet("background-color: rgba(0, 0, 0, 0.2); border-radius: 15px;");
    launchBlock->setFixedSize(662, 70);

    QVBoxLayout *leftLayout = new QVBoxLayout();
    leftLayout->addWidget(selectorBlock);
    leftLayout->addSpacing(2);

    QVBoxLayout *rightLayout = new QVBoxLayout();
    QHBoxLayout *topRightLayout = new QHBoxLayout();
    topRightLayout->addWidget(titleBlock);
    topRightLayout->addSpacing(2);
    topRightLayout->addWidget(playerBlock);
    rightLayout->addLayout(topRightLayout);
    rightLayout->addSpacing(2);
    rightLayout->addWidget(infoBlock);
    rightLayout->addSpacing(2);
    rightLayout->addWidget(descriptionBlock);
    rightLayout->addSpacing(2);
    rightLayout->addWidget(launchBlock);

    QHBoxLayout *mainHorizontalLayout = new QHBoxLayout();
    mainHorizontalLayout->addLayout(leftLayout);
    mainHorizontalLayout->addSpacing(2);
    mainHorizontalLayout->addLayout(rightLayout);

    mainLayout->addLayout(mainHorizontalLayout);

    centralWidget->setLayout(mainLayout);
    centralWidget->lower();
}

MainWindow::~MainWindow()
{
    delete ui;
}

