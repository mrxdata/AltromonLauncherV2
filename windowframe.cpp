#include "windowframe.h"

WindowFrame::WindowFrame(QWidget *parent)
    : QStackedWidget(parent)
{

}

WindowFrame::~WindowFrame()
{
}

void WindowFrame::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        QPoint globalPos = event->globalPosition().toPoint();

        QPoint windowTopLeft = mapToGlobal(QPoint(0, 0));

        QRect headerRect(windowTopLeft, QSize(HEADER_WIDTH, HEADER_HEIGHT));
        if (headerRect.contains(globalPos)) {
            m_isDragging = true;
            m_dragPosition = globalPos - frameGeometry().topLeft();
            event->accept();
        }
    }
}

void WindowFrame::mouseMoveEvent(QMouseEvent *event)
{
    if (m_isDragging) {
        QPoint newPos = event->globalPosition().toPoint() - m_dragPosition;
        move(newPos);
        event->accept();
    }
}

void WindowFrame::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_isDragging = false;
        event->accept();
    }
}
