#ifndef AUTHWINDOW_H
#define AUTHWINDOW_H

#include "basewindow.h"

namespace Ui {
class AuthWindow;
}

class AuthWindow : public BaseWindow
{
    Q_OBJECT

public:
    explicit AuthWindow(QWidget *parent = nullptr);
    ~AuthWindow();

private:
    Ui::AuthWindow *ui;
};

#endif // AUTHWINDOW_H
