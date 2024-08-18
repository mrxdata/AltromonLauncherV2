#include "headerpanel.h"
#include <QPainter>

HeaderPanel::HeaderPanel(QWidget *parent)
    : QWidget(parent)
{
    setFixedHeight(36);
    setAutoFillBackground(true);
}

HeaderPanel::~HeaderPanel()
{
}

void HeaderPanel::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);

    painter.setBrush(QColor(30, 30, 30));
    painter.setPen(Qt::NoPen);
    painter.drawRect(rect());

    QLinearGradient gradient(0, height() - 2, width(), height() - 2);
    gradient.setColorAt(0, Qt::cyan);
    gradient.setColorAt(1, Qt::magenta);

    QRect gradientRect(0, height() - 2, width(), 2);
    painter.fillRect(gradientRect, gradient);
}
