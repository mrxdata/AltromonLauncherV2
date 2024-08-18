#ifndef BASEWINDOW_H
#define BASEWINDOW_H

#include <QDialog>
#include "headerpanel.h"

namespace Ui {
class BaseWindow;
}

class BaseWindow : public QDialog
{
    Q_OBJECT

public:
    explicit BaseWindow(QWidget *parent = nullptr);
    ~BaseWindow();

private:
    Ui::BaseWindow *ui;
    HeaderPanel *headerPanel;
};

#endif // BASEWINDOW_H
