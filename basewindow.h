#ifndef BASEWINDOW_H
#define BASEWINDOW_H

#include <QDialog>

namespace Ui {
class BaseWindow;
}

class BaseWindow : public QDialog
{
    Q_OBJECT

public:
    explicit BaseWindow(QWidget *parent = nullptr);
    ~BaseWindow();

protected:

private:
    Ui::BaseWindow *ui;
};

#endif // BASEWINDOW_H
