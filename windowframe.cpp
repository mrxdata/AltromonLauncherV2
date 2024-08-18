#include "windowframe.h"

WindowFrame::WindowFrame(QWidget *parent)
    : QStackedWidget(parent), m_isDragging(false), m_headerPanel(nullptr)
{
}

WindowFrame::~WindowFrame() = default;

void WindowFrame::setHeaderPanel(QWidget *headerPanel)
{
    m_headerPanel = headerPanel;
}

void WindowFrame::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && m_headerPanel) {
        // Получаем размеры и положение headerPanel
        QRect headerRect = m_headerPanel->rect().translated(m_headerPanel->mapToGlobal(QPoint(0, 0)));

        // Проверяем, находится ли курсор в области headerPanel
        if (headerRect.contains(event->globalPosition().toPoint())) {
            m_isDragging = true;
            m_dragPosition = event->globalPosition().toPoint() - frameGeometry().topLeft();
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
