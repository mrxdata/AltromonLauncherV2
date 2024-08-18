#include "basewindow.h"
#include "ui_basewindow.h"
#include <QPalette>
#include <QPixmap>

BaseWindow::BaseWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::BaseWindow)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);
    setFixedSize(960, 540);
    setWindowTitle("Altromon Launcher");
    setWindowIcon(QIcon(":/resources/img/altromon-v2-64x.ico"));

    QPalette palette;
    QPixmap backgroundPixmap(":/resources/img/background.png");
    QPixmap scaledPixmap = backgroundPixmap.scaled(size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    palette.setBrush(QPalette::Window, QBrush(scaledPixmap));
    setPalette(palette);
    setAutoFillBackground(true);
}

BaseWindow::~BaseWindow()
{
    delete ui;
}

