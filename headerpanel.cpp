#include "headerpanel.h"
#include <QPainter>
#include <QLinearGradient>
#include <QGraphicsBlurEffect>

HeaderPanel::HeaderPanel(QWidget *parent)
    : QWidget(parent),
    iconLabel(new QLabel(this)),
    logoLabel(new QLabel(this))
{
    setFixedHeight(36);
    setAutoFillBackground(true);

    QPixmap iconPixmap(":/resources/img/altromon-64x-v2.png");
    iconLabel->setPixmap(iconPixmap);
    iconLabel->setFixedSize(24, 24);
    iconLabel->setScaledContents(true);
    iconLabel->move(10, (height() - iconLabel->height()) / 2);

    QPixmap logoPixmap(":/resources/img/altromonfontglow.png");
    if (!logoPixmap.isNull()) {
        logoLabel->setPixmap(logoPixmap);
        logoLabel->setFixedSize(logoPixmap.size()/5.5);
        logoLabel->setScaledContents(true);
        logoLabel->move(iconLabel->x() + iconLabel->width() + 2, (height() - logoLabel->height()) / 2);
    }
}

HeaderPanel::~HeaderPanel()
{
}

void HeaderPanel::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);

    //Background
    painter.setBrush(QColor(24, 24, 24)); // #181818
    painter.setPen(Qt::NoPen);
    painter.drawRect(rect());

    //GlowLine
    QLinearGradient gradient(0, height() - 2, width(), height() - 2);
    gradient.setColorAt(0, QColor(110, 100, 200)); // #6c62c7
    gradient.setColorAt(1, QColor(210, 120, 144)); // #bf6590

    QRect gradientRect(0, height() - 2, width(), 2);
    painter.fillRect(gradientRect, gradient);

}
