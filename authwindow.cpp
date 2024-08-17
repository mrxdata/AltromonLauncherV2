#include "authwindow.h"
#include "ui_authwindow.h"
#include <QMouseEvent>
#include <QIcon>
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QGraphicsBlurEffect>
#include <QVBoxLayout>

AuthWindow::AuthWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AuthWindow)
    , scene(new QGraphicsScene(this))
    , view(new QGraphicsView(scene, this))
    , pixmapItem(new QGraphicsPixmapItem())
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);
    setFixedSize(960, 540);

    setWindowTitle("Altromon Launcher");
    setWindowIcon(QIcon(":/resources/img/altromon-v2-64x.ico"));

    this->setStyleSheet("background-color: #0f131a;");

    QPixmap pixmap(":/resources/img/circles.png");

    QPixmap scaledPixmap = pixmap.scaled(pixmap.size() * 2, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    pixmapItem->setPixmap(scaledPixmap);

    QGraphicsBlurEffect *blurEffect = new QGraphicsBlurEffect();
    blurEffect->setBlurRadius(200);
    pixmapItem->setGraphicsEffect(blurEffect);

    scene->addItem(pixmapItem);
    scene->setSceneRect(0, 0, width(), height());

    view->setRenderHint(QPainter::Antialiasing);
    view->setRenderHint(QPainter::SmoothPixmapTransform);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setStyleSheet("border: none;");

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(view);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    setLayout(layout);

    updatePixmapPosition();
}

AuthWindow::~AuthWindow()
{
    delete ui;
}

void AuthWindow::updatePixmapPosition()
{
    QRectF sceneRect = scene->sceneRect();
    QRectF pixmapRect = pixmapItem->boundingRect();
    pixmapItem->setPos(sceneRect.center() - pixmapRect.center());
}

void AuthWindow::paintEvent(QPaintEvent *event)
{
    QDialog::paintEvent(event);
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


void AuthWindow::on_authButton_clicked()
{
    emit authSuccessful();

    // QString login = ui->loginForm->text();
    // QString password = ui->passwordForm->text();
    // if(login == "root" && password == "toor") {
    //         emit authSuccessful();
    // }
}
