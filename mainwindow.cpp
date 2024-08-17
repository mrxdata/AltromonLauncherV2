#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPixmap>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , scene(new QGraphicsScene(this))
    , view(new QGraphicsView(scene, this))
    , pixmapItem(new QGraphicsPixmapItem())
{
    ui->setupUi(this);

    // Устанавливаем центральный виджет
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Создаем макет и добавляем QGraphicsView
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    layout->addWidget(view);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

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

    updatePixmapPosition();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updatePixmapPosition()
{
    QRectF sceneRect = scene->sceneRect();
    QRectF pixmapRect = pixmapItem->boundingRect();
    pixmapItem->setPos(sceneRect.center() - pixmapRect.center());
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QMainWindow::paintEvent(event);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_dragStartPosition = event->globalPosition().toPoint();
        event->accept();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        const QPoint delta = event->globalPosition().toPoint() - m_dragStartPosition;
        move(pos() + delta);
        m_dragStartPosition = event->globalPosition().toPoint();
        event->accept();
    }
}
