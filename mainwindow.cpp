#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : BaseWindow(parent),
    ui(new Ui::MainWindow)
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
