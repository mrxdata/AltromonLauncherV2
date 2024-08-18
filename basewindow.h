#ifndef BASEWINDOW_H
#define BASEWINDOW_H

#include <QWidget>
#include <QPoint>

namespace Ui {
class BaseWindow;
}

class BaseWindow : public QWidget
{
    Q_OBJECT

public:
    explicit BaseWindow(QWidget *parent = nullptr);
    ~BaseWindow();

protected:
    void setupBaseWindow(); // Метод для установки общих свойств окна
    bool eventFilter(QObject *obj, QEvent *event) override;

private:
    Ui::BaseWindow *ui;
    QPoint m_dragStartPosition;

    void setupDragMove(); // Метод для инициализации перетаскивания
};

#endif // BASEWINDOW_H
