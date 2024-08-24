#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>


MainWindow::MainWindow(QWidget *parent)
    : BaseWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setContentsMargins(15, 50, 15, 15); // Отступы: сверху 51 пиксель, остальные по 15 пикселей

    // Блоки
    QWidget *topBlock = new QWidget(centralWidget);
    topBlock->setStyleSheet("background-color: rgba(0, 0, 0, 0.2); border-radius: 15px;");
    topBlock->setFixedSize(654, 135);

    QWidget *serverTitleBlock = new QWidget(centralWidget);
    serverTitleBlock->setStyleSheet("background-color: rgba(0, 0, 0, 0.2); border-radius: 15px;");
    serverTitleBlock->setFixedSize(654, 93);

    QWidget *serverDescriptionBlock = new QWidget(centralWidget);
    serverDescriptionBlock->setStyleSheet("background-color: rgba(0, 0, 0, 0.2); border-radius: 15px;");
    serverDescriptionBlock->setFixedSize(654, 140);

    QWidget *launchBlock = new QWidget(centralWidget);
    launchBlock->setStyleSheet("background-color: rgba(0, 0, 0, 0.2); border-radius: 15px;");
    launchBlock->setFixedSize(934, 70);

    QWidget *playerBlock = new QWidget(centralWidget);
    playerBlock->setStyleSheet("background-color: rgba(0, 0, 0, 0.2); border-radius: 15px;");
    playerBlock->setFixedSize(266, 393);

    // Layouts
    QVBoxLayout *leftLayout = new QVBoxLayout();
    leftLayout->addWidget(topBlock);
    leftLayout->addSpacerItem(new QSpacerItem(0, 6)); // Отступ между блоками
    leftLayout->addWidget(serverTitleBlock);
    leftLayout->addSpacerItem(new QSpacerItem(0, 7)); // Отступ между блоками
    leftLayout->addWidget(serverDescriptionBlock);

    QHBoxLayout *mainHorizontalLayout = new QHBoxLayout();
    mainHorizontalLayout->addLayout(leftLayout);
    mainHorizontalLayout->addSpacerItem(new QSpacerItem(5, 0)); // Отступ между блоками
    mainHorizontalLayout->addWidget(playerBlock);

    mainLayout->addLayout(mainHorizontalLayout);
    mainLayout->addSpacerItem(new QSpacerItem(0, 7)); // Отступ между блоками
    mainLayout->addWidget(launchBlock);

    centralWidget->setLayout(mainLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}
