#include "authwindow.h"
#include "ui_authwindow.h"
#include <QMouseEvent>
#include <QIcon>

AuthWindow::AuthWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AuthWindow)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);
    setFixedSize(960, 540);

    setWindowTitle("Altromon Launcher");
    setWindowIcon(QIcon(":/resources/img/altromon-v2-64x.ico"));

}

AuthWindow::~AuthWindow()
{
    delete ui;
}

void AuthWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_dragStartPosition = event->globalPosition().toPoint();
        event->accept();
    }
}

void AuthWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        const QPoint delta = event->globalPosition().toPoint() - m_dragStartPosition;
        move(pos() + delta);
        m_dragStartPosition = event->globalPosition().toPoint();
        event->accept();
    }
}
