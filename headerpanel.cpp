#include "headerpanel.h"
#include <QPainter>

HeaderPanel::HeaderPanel(QWidget *parent)
    : QWidget(parent)
{
    setFixedHeight(30);
    setAutoFillBackground(true);
}

HeaderPanel::~HeaderPanel()
{
}

void HeaderPanel::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(QColor(30, 30, 30));
    painter.setPen(Qt::NoPen);
    painter.drawRect(rect());
}
