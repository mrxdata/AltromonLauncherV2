#include "basewindow.h"
#include "ui_basewindow.h"
#include <QVBoxLayout>

BaseWindow::BaseWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::BaseWindow)
{
    ui->setupUi(this);

    setFixedSize(960, 540);
    setWindowTitle("Altromon Launcher");

    QPalette palette;
    QPixmap backgroundPixmap(":/resources/img/background.png");
    QPixmap scaledPixmap = backgroundPixmap.scaled(size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    palette.setBrush(QPalette::Window, QBrush(scaledPixmap));
    setPalette(palette);
    setAutoFillBackground(true);


    headerPanel = new HeaderPanel(this);
    headerPanel->setGeometry(0, 0, width(), 30);
}

BaseWindow::~BaseWindow()
{
    delete ui;
}
