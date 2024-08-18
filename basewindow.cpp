#include "basewindow.h"
#include "ui_basewindow.h"
#include <QMouseEvent>
#include <QPalette>
#include <QPixmap>
#include <QIcon>

BaseWindow::BaseWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BaseWindow)
{
    ui->setupUi(this);

    setupBaseWindow(); // Настройка общих свойств
    setupDragMove();   // Инициализация перетаскивания
}

BaseWindow::~BaseWindow()
{
    delete ui;
}

void BaseWindow::setupBaseWindow()
{
    // Установка безрамочности и фиксированного размера
    setWindowFlags(Qt::FramelessWindowHint);
    setFixedSize(960, 540);

    // Установка заголовка окна и иконки
    setWindowTitle("Altromon Launcher");
    setWindowIcon(QIcon(":/resources/img/altromon-v2-64x.ico"));

    // Установка фонового изображения
    QPalette palette;
    QPixmap backgroundPixmap(":/resources/img/background.png");
    QPixmap scaledPixmap = backgroundPixmap.scaled(size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    palette.setBrush(QPalette::Window, QBrush(scaledPixmap));
    setPalette(palette);
    setAutoFillBackground(true);
}

void BaseWindow::setupDragMove()
{
    installEventFilter(this); // Установка фильтра событий для перетаскивания окна
}

bool BaseWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        if (mouseEvent->button() == Qt::LeftButton) {
            m_dragStartPosition = mouseEvent->globalPosition().toPoint();
            return true;
        }
    } else if (event->type() == QEvent::MouseMove) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        if (mouseEvent->buttons() & Qt::LeftButton) {
            const QPoint delta = mouseEvent->globalPosition().toPoint() - m_dragStartPosition;
            move(pos() + delta);
            m_dragStartPosition = mouseEvent->globalPosition().toPoint();
            return true;
        }
    }
    return QWidget::eventFilter(obj, event);
}
