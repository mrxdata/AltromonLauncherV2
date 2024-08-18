#ifndef WINDOWFRAME_H
#define WINDOWFRAME_H

#include <QStackedWidget>
#include <QMouseEvent>

class WindowFrame : public QStackedWidget
{
    Q_OBJECT

public:
    explicit WindowFrame(QWidget *parent = nullptr);
    ~WindowFrame() override;
    void setHeaderPanel(QWidget *headerPanel);


protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    bool m_isDragging;
    QPoint m_dragPosition;
    QWidget *m_headerPanel;
    // static const int HEADER_HEIGHT = 36;
    // static const int HEADER_WIDTH = 960;
};

#endif // WINDOWFRAME_H
